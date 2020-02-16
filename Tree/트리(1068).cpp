#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector< vector<int> > inputs;
int Answer;

void delete_node(int node) {
	/* 현재 존재하지 않는 노드이므로 답에서 제외 */ 
	--Answer;
	
	if(inputs[node].size()==0) return;
	
	for(int i=0;i<inputs[node].size();++i) 
		delete_node(inputs[node][i]);

	inputs[node].clear();	
}

int main(void)
{
	int N;
	int parent_node, remove_node;
	
	cin >> N;
	inputs.resize(N);
	
	/* 루트노드는 추가안함 */ 
	for(int i=0;i<N;++i) {
		cin >> parent_node;
		if(parent_node==-1) continue;
		inputs[parent_node].push_back(i);
	}
	
	/* 삭제할 노드 입력받음*/ 
	cin >> remove_node;
	
	/* 먼저 삭제할 노드를 가지고있는 부모노드의 자식노드목록에서 해당 노드를 지움*/ 
	for(int i=0;i<inputs.size();++i)
		for(int j=0;j<inputs[i].size();++j)
			if(inputs[i][j]==remove_node) {
				inputs[i].erase(inputs[i].begin()+j);
			}
			
	/* 그리고 나서 삭제할 노드의 하위노드들을 모두 dfs로 지움 */ 
	delete_node(remove_node);
	
	/* 리프노드 후보들을 추가 */ 
	for(int i=0;i<inputs.size();++i)
		if(inputs[i].size()==0)
			++Answer;
			
	cout << Answer << endl;
	
	return 0;
}
