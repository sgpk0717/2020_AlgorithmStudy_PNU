// ���� 1068�� < Ʈ�� >
// �޸�: 1984KB		�ð�: 0ms 
#include <iostream>
#include <array>
#include <queue>
using namespace std;

int N, rmNode;
array< int, 50 > List;

void input() {
	cin >> N;
	for(int i=0; i<N; i++) { cin >> List[i]; }
	cin >> rmNode;
}

void remove() {
	queue< int > rmlist;
	
	List[rmNode] = -2;
	rmlist.push(rmNode);
	
	while( !rmlist.empty() ) {
		int target = rmlist.front();
		
		for(int i=0; i<N; i++) {
			if( List[i] == target ) {
				List[i] = -2;		// �������°� -2�� �ٲ� 
				rmlist.push(i);
			}
		}
		rmlist.pop();
	}
}

int leaf() {
	int cnt = 0;
	int i,j;
	
	for(i=0; i<N; i++) {			// i: target node
		if( List[i] != -2 ){
			for(j=0; j<N; j++) {	// j: parent of each node
				// node i�� node j�� parent�̸�, i�� leaf �ƴϹǷ� break 
				if( i == List[j] ) { break; }
			}
			if( !(j<N) ) { cnt++; }		// loof �� ���� ������ i�� leaf 
		}
	}	
	return cnt;
}

int main(void) {
	input();
	remove();

	int leaf_n = leaf();
	cout << leaf_n;
	return 0;
}

