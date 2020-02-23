// ���� 1931�� < ȸ�ǽ� ���� > 
//  �޸�: 3532KB		�ð�: 88ms 
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

�� �������� (5 8)���� (8 8)�� ���� �˻��Ѱ� ��������.
������ �ð� �����θ� �����ߴ� ��Ŀ���
���� �ð��� ������ ���� ������ ������� �����ϵ��� �ٲ��. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pair_ii;
vector < pair_ii > Meeting;

bool func_end( pair_ii &p1, pair_ii &p2 ) { // ���� ������ ������ ���� 
	if( p1.second == p2.second ) 			// ������ �ð��� ������ 
		return p1.first < p2.first;			// ���� ������ ������ 
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
		if( Meeting[i].first >= prev_meeting.second ) {	// �Ȱ�ġ�� 
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

