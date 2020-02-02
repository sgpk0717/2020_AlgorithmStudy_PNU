// 백준 6359번 < 만취한 상범 > 
// 메모리: 1984KB		시간: 4ms 
/*
 * DP알고리즘을 이용해서 어떻게 풀어야할 지 고민하는데 오래결림. 
 */
#include <iostream>
#include <vector>
using namespace std;

int solve( int room_N ) {
	vector< bool > room(room_N+1, 0);
	int count = 0;
	
	for(int round=1; round<=room_N; round++) { // 라운드 넘버 
		for(int i=round; i<=room_N; i++) {		// 탐색 
			if( i%round == 0 ) {
				room[i] = !room[i];
			}
		}
	}
	
	for(int i=1; i<=room_N; i++) { count += room[i]; }
	return count;
}

int main(void) {
	vector< int > result;
	int case_N, room_N, res;
	cin >> case_N;
	
	for(int i=0; i<case_N; i++) {
		cin >> room_N;
		res = solve( room_N );
		result.push_back(res);
	} 

	for(auto s: result) { cout << s << endl; }
	return 0;
}

