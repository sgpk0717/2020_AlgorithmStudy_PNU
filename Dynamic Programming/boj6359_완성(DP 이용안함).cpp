// ���� 6359�� < ������ ��� > 
/*
	�������� ���� ���� �������� ����� Ȧ���������Ѵ�.
	�׷��Ƿ� 1�� �������̴�. 
*/
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector< int > result;
	int case_N;
	cin >> case_N;
	
	for(int i=0; i<case_N; i++) {
		int room;
		cin >> room;
		
		for(int num=10; num>1; num--) {
			if( room >= num*num ) {
				result.push_back( num );
				break;
			}
		}
	} 

	for(auto s: result) { cout << s << endl; }
	return 0;
}

