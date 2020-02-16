/*
���⼺�� �����Ƿ� tree�� (parent, child), (child, parent) ��� ���� 
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector< pair<int, int> > edges; // first: parent or child, second: weight 

int n;
edges tree[1001];
vector<bool> visited(1001, false);
int last;
int diameter;

void solve(int beg, int weight)
{
	if(visited[beg])	return;
	else {
		visited[beg] = true;
		if(diameter<weight) {
			diameter = weight;
			last = beg;
		}
		
		for(int i=0; i<tree[beg].size(); ++i) {
			solve(tree[beg][i].first, weight + tree[beg][i].second);
		}
	}
}
int main(void)
{
//	ifstream ifs("1967_1.inp");
//	ifs >> n; // ����� ����(1<=n<=10000) 
	cin >> n;
	
	int p, c, w; // parent, child, weight 
	
	for(int i=0; i<n; ++i) {
//		ifs >> p >> c >> w;
		cin >> p >> c >> w;
		tree[p].push_back(make_pair(c,w));
		tree[c].push_back(make_pair(p,w));
	}
//	ifs.close();
	
	solve(1, 0); // root���� ���� �� �� ã��  
 
	for(int i=0; i<n+1; ++i)		visited[i] = false;
	diameter = 0;

	solve(last, 0); // ������ ã�� ������ ���� �� �� ã�� 
	cout << diameter;
	
	return 0;
}
