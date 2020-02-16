#include <iostream>
#include <fstream>
#include <vector>

#define UNVISITED 	0
#define VISITED 	1
#define LEAF		2

using namespace std;

int N;
int length;
int max_length=0;
int max_node; 
vector<int> visited;
vector< vector< pair<int,int> > > tree;

void explore(int node) {
//	printf("========%d번 노드를 방문.========\n",node); 
	
	for(int i=0;i<tree[node].size();++i) {
		if( visited[ tree[node][i].first ] == UNVISITED ) {	// 방문한적이 없다면 
//			printf("%d번 노드를 방문한적이 없으므로 방문함.\n",tree[node][i].first); 
			visited[ tree[node][i].first ] = VISITED;	// 방문했다고 표시하고 
			length += tree[node][i].second;				// 거리를 더하고 
//			printf("거리 %d를 더함.\n", tree[node][i].second);
			explore( tree[node][i].first );				// 방문해라. 
//			printf("%d번 노드 방문끝.\n",tree[node][i].first); 
			visited[ tree[node][i].first ] = UNVISITED;	// 끝나면 다시 안간걸로하고
			length -= tree[node][i].second;				// 거리를 빼라. 
//			printf("거리 %d를 뺌.\n", tree[node][i].second);
		} 
		else if( visited[ tree[node][i].first ] == LEAF ) {
//			printf("%d번 노드가 리프노드임.\n", tree[node][i].first); 
			if(length + tree[node][i].second > max_length) {
//				printf("length가 %d이고 max_length가 %d이므로 바꿈.\n",length + tree[node][i].second,max_length); 
				max_length = length + tree[node][i].second;
				max_node   = tree[node][i].first;
			} else {
//				printf("length가 %d이고 max_length가 %d이므로 안바꿈.\n",length + tree[node][i].second,max_length); 
			}
		}
	}
}

void set_leaf(void) {
	for(int i=2;i<=N;++i)	
		if(tree[i].size()==1)
			visited[i]=LEAF;
}

int main(void)
{
	int n1,n2,distance;
	
	ifstream ifs("1967_1.txt");
//	ifs >> N;
	cin >> N;

	visited.resize(N+1);
	tree.resize(N+1);
	for(int i=0;i<N-1;++i) {
//		ifs >> n1 >> n2 >> distance;
		cin >> n1 >> n2 >> distance;
		tree[n1].push_back(pair<int,int>(n2,distance));
		tree[n2].push_back(pair<int,int>(n1,distance));
	}
	set_leaf();
	
//	for(int i=0;i<tree.size();++i) {
//		printf("%d번째 노드와 연결된 노드: ",i); 
//		for(int j=0;j<tree[i].size();++j) 
//			printf("(%d번,%d) ",tree[i][j].first,tree[i][j].second); 
//		cout << endl;
//	}

	visited[1]=VISITED;
	explore(1);
	visited[1]=UNVISITED;
	
	explore(max_node);
	
	cout << max_length << endl;
	
	return 0;
}

