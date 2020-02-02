// 백준 6359번 < 만취한 상범 > 
/*
	마지막에 문이 열려 있으려면 약수가 홀수개여야한다.
	그러므로 1과 제곱수이다. 
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

