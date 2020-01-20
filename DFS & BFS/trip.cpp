// 80ms
#include <iostream>
#include <vector>

using namespace std;

/*
	���� ���� '����' �� ����� ��� ������ ������ ���� Ƚ���� �ƴ϶�
	������ ������ �����ϸ� �ȴ�. 
	�̹� �湮�� ������ ������ �ȴ�.
	�׻� ����׷����� �̷��.
	-> ��� Vertex�� �湮�ϸ鼭, �ּ��� Edge�� ���� ���� ���ϴ� �� �̹Ƿ�
	-> Spanning tree ������. 
	-> Spanning tree�� edge ���� vertex-1 �̴�. 
*/

int main(void) {
	int T, N, M;
	vector<int> vertex;
	
	cin >> T;
	for(int t=0; t<T; ++t) {
		cin >> N >> M;
		vertex.push_back(N);
		for(int m=0; m<M; ++m) {
			int a, b;
			cin >> a >> b;
		}
	}
	
	for(int i=0; i<T; ++i) { // vertex -1 �� ���. 
		cout << vertex[i] - 1 << endl;
	}
	
	return 0;
}
