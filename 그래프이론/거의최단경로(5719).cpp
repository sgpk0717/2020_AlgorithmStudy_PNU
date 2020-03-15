#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#define INF 9999999

using namespace std;

int N, M, S, D;
int previous_shortest_length;
int current_shortest_length;
vector< vector< pair<int,int> > > roads;
vector< vector< pair<int,int> > > adj_roads;
vector<bool> visited;				// 이미 방문한 노드 표시 
vector<int>  shortest_length;		// 시작점부터 각 노드까지의 최단거리를 표시할 벡터
vector< vector<int> > shortest_path;
queue< pair<int,int> > edge_basket;
vector<bool> adj_checked;

void find_similar_path(const vector<int>&);

void print_adj_roads(void) {
	for(int i=0;i<adj_roads.size();++i) {
		cout << i << "번 노드로 오는길: "; 
		for(int j=0;j<adj_roads[i].size();++j) {
			printf("(%d,%d) ",adj_roads[i][j].first, adj_roads[i][j].second);
		}
		cout << endl;
	}
}

void print_shortest_length(void) {	
	cout << "===============shortest===============" << endl;
	for(int i=0;i<shortest_length.size();++i) { 
		if(shortest_length[i]==INF)
			cout << "INF" << '\t'; 
		else
			cout << shortest_length[i] << '\t';
	}
	cout << endl;
	cout << "======================================" << endl;
}

void print_shortest_path(int target_node) {
	cout << "===========" << target_node << "까지의 최단경로==========" << endl; 
	for(int i=0;i<shortest_path[target_node].size();++i)
		cout << shortest_path[target_node][i] << '\t';
	cout << endl;
	cout << "==============================" << endl;
}

/* shortest 벡터에서 가장 짧은 거리의 노드를 반환 */ 
int get_min_node(void) {
	int min_value = INF;
	int min_node = -1;
	for(int i=0;i<shortest_length.size();++i)	{
		if(visited[i]) continue;
		if(min_value > shortest_length[i]) {
			min_value = shortest_length[i];
			min_node = i;		
		}
	}
	
	return min_node;
}

void delete_edge(int source, int destination) {
	for(int i=0;i<roads[source].size();++i) {	
		if(roads[source][i].first == destination) {
			roads[source].erase(roads[source].begin()+i);	
			break;
		}
	}
}

void delete_shortest_path(int target) {
	for(int i=0;i<shortest_path[target].size()-1;++i) 
		delete_edge(shortest_path[target][i], shortest_path[target][i+1]);	
}

void find_adj_path(int target) {
	if(adj_checked[target]) return;
	adj_checked[target]=true;
	for(int i=0;i<adj_roads[target].size();++i) {
		if( shortest_length[ adj_roads[target][i].first ] + adj_roads[target][i].second 
			== shortest_length[target] ) {
			edge_basket.push(pair<int,int>( adj_roads[target][i].first, target ));
			find_similar_path(shortest_path[adj_roads[target][i].first]);
		}
	}
}

void find_similar_path(const vector<int>& path) {
	for(int i=path.size()-1;i>=1;--i) {
		find_adj_path(path[i]);		
	}
}

void clean_basket(void) {
	int source, destination;
	while(!edge_basket.empty()) {
		source = edge_basket.front().first;
		destination = edge_basket.front().second;
		edge_basket.pop();
		delete_edge(source,destination);		
	}
}

void processing(int target) {
	visited[target] = true;

	int dist, min_node, search_node, search_edge;
	for(int i=0;i<roads[target].size();++i) {
		search_node = roads[target][i].first;
		search_edge = roads[target][i].second;
		
		dist = shortest_length[target]+search_edge;
		if(shortest_length[search_node] > dist) { // 방금 찾은 경로가 더 짧을때 
			shortest_length[search_node] = dist;			
			shortest_path[search_node] = shortest_path[target];
			shortest_path[search_node].push_back(search_node); 
		}
	}
	
	min_node = get_min_node();
	if(min_node==-1) return;
	
	processing(min_node);
}

int main(void)
{
	int U, V, P;
	while(true) {
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		roads.clear();
		visited.clear();
		shortest_length.clear();
		shortest_path.clear();
		adj_roads.clear();
		adj_checked.clear();
		
		roads.resize(N);
		visited.resize(N);
		shortest_length.resize(N,INF);
		shortest_path.resize(N);
		adj_roads.resize(N);
		adj_checked.resize(N);
		
		cin >> S >> D;
		
		for(int i=0;i<M;++i) {	
			cin >> U >> V >> P;
			roads[U].push_back(pair<int,int>(V,P));
			adj_roads[V].push_back(pair<int,int>(U,P));
		}
		
		/* 방문 표시 */
		shortest_length[S]=0;
		shortest_path[S].push_back(S);
		
		/* 탐색 시작 */ 
		processing(S);
		
		previous_shortest_length = shortest_length[D];	// 이전 최단경로길이 저장
		if(previous_shortest_length == INF) {
			cout << -1 << endl;
			continue;
		}
		
		/* 비슷한 경로 삭제 추가 */
		find_similar_path(shortest_path[D]);
		
		clean_basket();
		delete_shortest_path(D);	// 목적지까지의 최단경로에 포함된 엣지 삭제 
		
		while(true) {
			visited.clear();
			shortest_length.clear();
			shortest_path.clear();
			
			visited.resize(N);
			shortest_length.resize(N,INF);
			shortest_path.resize(N);
			
			/* 방문 표시 */
			shortest_length[S]=0;
			shortest_path[S].push_back(S);
			
			/* 탐색 시작 */ 
			processing(S);
			current_shortest_length = shortest_length[D];
			
			if(current_shortest_length == INF) {
				cout << -1 << endl;
				break;	
			}
			
			if(current_shortest_length == previous_shortest_length) {
				delete_shortest_path(D);	
			} else {
				cout << current_shortest_length << endl;
				break;			
			}							
		}
	}
	
	return 0;
}
