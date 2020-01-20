/*
	A�� B�� �ŷ��Ѵ�. -> B�� ��ŷ�ϸ� A�� ��ŷ �� �� �ִ�. 
	but, A�� ��ŷ�Ѵٰ� �ؼ� B�� ��ŷ�� �� �ִ°� �ƴϴ�.
	��, �ܹ��� �׷�����.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max_N 10001 // �ε��� 1���� �����ҰŴϱ� 10000�� �ƴ� 10001�� �ش�. 

int N, M;
vector<int> adj[max_N];
vector<int> answer;
vector<int> deep(1, 0); // �� ��尡 �󸶳� ��ŷ �� �� �ִ°� ����.
int cnt;

void Input(void) {
	cin >> N >> M;
	for(int i=0; i<M; ++i) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
}

void DFS(int node) {
	++cnt;
	if( adj[node].empty() )
		return;
	int deep_size = deep.size();
	for(int i=0; i<adj[node].size(); ++i) {
		if(i>=1) --cnt; // �ϳ��� ��忡 ���� edge�� ������ �ߺ� cnt ���� ����. 
		if(adj[node][i] <= deep_size) { // �̹� ������ ���� DFS Ž�� ����. 
			cnt += deep[adj[node][i]];
		}
		else { 
			DFS(adj[node][i]);
		}
	}
}

void find_max_value_index(int max_value) {
	for(int i=0; i<deep.size(); ++i) {
		if(deep[i] == max_value) { // �ִ� ���� ���� �ε����� ����. 
			answer.push_back(i);
		}
	}
}

void Solve(void) {
	for(int i=1; i<=N; ++i) {
		cnt = 0;
		DFS(i); // �� ��庰�� ���� Ž��. 
		deep.push_back(cnt);
	}	
	auto it = max_element(deep.begin(), deep.end());
	int max_value = *it;
	find_max_value_index(max_value);
	sort(answer.begin(), answer.end());
}

void Print(void) {
	for(int i=0; i<answer.size(); ++i)
		cout << answer[i] << " ";
	cout << endl;
}

int main(void) {
	Input();
	Solve();
	Print();
	return 0;
}
