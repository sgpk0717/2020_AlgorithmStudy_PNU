// memory : 1984 KB
// time : 0 ms

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	int female, male, intern, rest=0, num_team=0;
	cin >> female >> male >> intern;
	
		
	if(female/2 > male) {
		rest += female - male*2;
	}
	else if(female/2 < male) {
		rest += male - female/2;
		male -= rest;
		if(female%2 != 0)		// ���ڰ� Ȧ������ �Ѹ� ���� --> ���ϼ��� �߰� 
			rest++;
	}
	else {
		;
	}
	
	while(rest < intern){
		rest+=3;
		male--;
	}
	num_team = male;
	cout << num_team << endl;
}

