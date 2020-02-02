// ���� 6359�� < ������ ��� > 
// �޸�: 1984KB		�ð�: 4ms 
/*
 * DP�˰����� �̿��ؼ� ��� Ǯ����� �� ����ϴµ� �����Ḳ. 
 */
#include <iostream>
#include <vector>
using namespace std;

int solve( int room_N ) {
	vector< bool > room(room_N+1, 0);
	int count = 0;
	
	for(int round=1; round<=room_N; round++) { // ���� �ѹ� 
		for(int i=round; i<=room_N; i++) {		// Ž�� 
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

