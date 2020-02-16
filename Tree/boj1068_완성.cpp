// 백준 1068번 < 트리 >
// 메모리: 1984KB		시간: 0ms 
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
				List[i] = -2;		// 없어지는건 -2로 바꿈 
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
				// node i가 node j의 parent이면, i는 leaf 아니므로 break 
				if( i == List[j] ) { break; }
			}
			if( !(j<N) ) { cnt++; }		// loof 다 돌고 나오면 i는 leaf 
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

