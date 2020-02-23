// 백준 2875번 < 대회or인턴 >
// 메모리: 1984 KB		시간: 0ms 
#include <iostream>
using namespace std;

int Intern, Cnt;

void make_team( int girl, int boy ) {
	if( girl + boy < Intern ) {		// 남은 인원이 인턴보낼 인원보다 작으면 
		Cnt--;						// 카운트 하나 감소  
		return ;
	}
	
	// 인원은 충분한데 여2 남1 팀을 만들 수 없는 경우 
	if( girl < 2 || boy < 1 ) { return ; }	 
	
	Cnt++;
	make_team( girl-2, boy-1 );
} 

int main(void) {
	int girl, boy;
	cin >> girl >> boy >> Intern;
	make_team( girl, boy );

	cout << Cnt;
	return 0;
}

