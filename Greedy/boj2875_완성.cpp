// ���� 2875�� < ��ȸor���� >
// �޸�: 1984 KB		�ð�: 0ms 
#include <iostream>
using namespace std;

int Intern, Cnt;

void make_team( int girl, int boy ) {
	if( girl + boy < Intern ) {		// ���� �ο��� ���Ϻ��� �ο����� ������ 
		Cnt--;						// ī��Ʈ �ϳ� ����  
		return ;
	}
	
	// �ο��� ����ѵ� ��2 ��1 ���� ���� �� ���� ��� 
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

