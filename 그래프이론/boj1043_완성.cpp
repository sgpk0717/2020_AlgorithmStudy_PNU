/*
 * 백준 1043번 < 거짓말 > 
 * 메모리: 1988KB		시간: 0ms 
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, Know_Cnt;			// N: 인원 수, M: 파티 수 
vector< vector< int > > PartyList; 
vector< int > Tell_Truth, Visit;	
queue< int > Know_Human;	// 진실 아는사람과 연결된사람 

void input() {
	int know_human, human_N_of_party, human;
	
	cin >> N >> M >> Know_Cnt;
	PartyList.resize( M );
	Tell_Truth.resize( M, 0 );
	
	for(int i=0; i<Know_Cnt; i++) {		// queue에 진실 아는사람 넣기 
		cin >> know_human;
		Know_Human.push( know_human );
		Visit.push_back( know_human );
	}
	
	for(int i=0; i<M; i++) {
		cin >> human_N_of_party;
		for(int j=0; j<human_N_of_party; j++) {
			cin >> human;
			PartyList[i].push_back( human );
		}
	}
}

bool visited( int person ) {
	for(auto s: Visit) {
		if( s == person ) { return true; }
	}
	return false;
}

void tell_truth( int index, vector< int > &knowlist ) {
	Tell_Truth[index] = 1;			// 해당 파티는 진실으로 
	for(auto s: knowlist) {			
		if( !visited(s) ) {			// 진실을 말해야할사람 찾기 
			Know_Human.push(s);
			Visit.push_back(s);
		}
	}
}

void solve() {
	while( !Know_Human.empty() ) {
		int know_human = Know_Human.front();
		Know_Human.pop();
		
		for(int i=0; i<M; i++) {
			for( auto human: PartyList[i] ) {
				if( human == know_human ) {
					tell_truth( i, PartyList[i] );
				}
			}
		}		
	}
}

int main(void) {
	int result = 0;
	
	input();
	solve();
	
	for(auto truth: Tell_Truth) {
		if( truth == 0 ) { result++; }
	}
	
	cout << result;
	return 0;
}

