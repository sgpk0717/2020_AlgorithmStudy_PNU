// 0ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define max_M 100
#define max_N 100

int M, N; // �Է¹��� ������ ũ��. 
int Graph_paper[max_N][max_M] = {-1, }; // �Ⱦ��� ��: -1, �湮���� ���� ��: 0, �湮�� ��: 1
int area; // �� ������ ����. 

typedef struct {
	int x, y;
} Direction;

Direction Dir[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} }; // Ž�� ���� ��������. 

void DFS(int x, int y) {
	if(Graph_paper[x][y] == 1) // �̹� �湮�� ���̶�� �׳� �������´�. 
		return;
		
	Graph_paper[x][y] = 1; // �湮���� ���� ���̶�� �湮�ߴٰ� ǥ��. 
	++area; // ���� 1 ����. 
	
	for(int i=0; i<4; ++i) { // ������������ �ѹ��� ���鼭 DFS Ž��. 
		int next_x = x + Dir[i].x; // x�� ���� ���ϱ�. 
		int next_y = y + Dir[i].y; // y�� ���� ���ϱ�. 
		if(next_x >= 0 && next_x < N && // �̶�, ������ �����ؾ� ��. 
			next_y >= 0 && next_y < M)
			if(Graph_paper[next_x][next_y] == 0) // �湮���� ������ ã���� �װ� DFS ���Ž��. 
				DFS(next_x, next_y);
	}
}

int main(void) {
	int K;
	cin >> M >> N >> K;
	
	vector<int> Areas; // �� ������ ���̸� ���. 
	
	// ������� ������ 0���� �ʱ�ȭ.
	for(int x=0; x<N; ++x) {
		for(int y=0; y<M; ++y) {
			Graph_paper[x][y] = 0;
		}
	} 
	
	// �����̿� ���� ä���. 
	int x1, y1, x2, y2;
	for(int i=0; i<K; ++i) {
		cin >> x1 >> y1 >> x2 >> y2; // x: n, y: m
		for(int x=x1; x<x2; ++x) {
			for(int y=y1; y<y2; ++y) {
				Graph_paper[x][y] = 1;
			}
		}		
	}
	//
	
	for(int x=0; x<N; ++x) {
		for(int y=0; y<M; ++y) {
			if(Graph_paper[x][y] == 0) { // �湮���� ���� ������ ã��. 
				area = 0; // �� �� ���� 0���� ������ DFS�� Ž��. �� �������� 0���� ����. 
				DFS(x,y);
				Areas.push_back(area); // �� ������ DFS�� ������ �� ������ area�� ����. 
			}
		}
	}
	
	cout << Areas.size() << endl;
	
	sort(Areas.begin(), Areas.end());
	
	for(int i=0; i<Areas.size(); ++i)
		cout << Areas.at(i) << " ";
	cout << endl;
	
	return 0;
}
