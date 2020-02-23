// 백준 1931번 < 회의실 배정 > 
//  메모리: 3532KB		시간: 88ms 
/*
9 
3 3
3 4
2 5 
2 7
8 8
8 8 
5 8
1 10
10 10

이 예제에서 (5 8)보다 (8 8)을 먼저 검사한게 문제였다.
끝나는 시간 순으로만 정렬했던 방식에서
같은 시간에 끝나면 먼저 시작한 순서대로 정렬하도록 바꿨다. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pair_ii;
vector < pair_ii > Meeting;

bool func_end( pair_ii &p1, pair_ii &p2 ) { // 일찍 끝나는 순으로 정렬 
	if( p1.second == p2.second ) 			// 끝나는 시간이 같으면 
		return p1.first < p2.first;			// 일찍 시작한 순으로 
	else
		return p1.second < p2.second;
}

void input() {
	int meeting_N;
	cin >> meeting_N;
	
	for(int i=0; i<meeting_N; i++) {
		int start_time, end_time;
		cin >> start_time >> end_time;
		Meeting.push_back( make_pair(start_time, end_time) );
	}
}

int schedule() {
	int cnt = 0;
	pair_ii prev_meeting = make_pair( 0,0 );
	
	for(int i=0; i<Meeting.size(); i++) {
		if( Meeting[i].first >= prev_meeting.second ) {	// 안겹치면 
	//		cout << Meeting[i].first << ' ' << Meeting[i].second << endl;
			prev_meeting = Meeting[i];
			cnt++;
		}
	}
	
	return cnt;
}

int main(void) {
	input();
	sort( Meeting.begin(), Meeting.end(), func_end );
	cout << schedule();	
	return 0;
}

