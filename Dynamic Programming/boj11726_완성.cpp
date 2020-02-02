// 백준 11726번 < 2xn 타일링 >
// 메모리: 1984 KB		시간: 0 ms
#include <iostream>
#include <vector>
#define DIV 10007
using namespace std;
// i-1랑 i-2 저장할때 안나눴더니 오버플로우 발생해서 틀렸었음 
int main(void) {
	vector< long long > fibo(2,1);
	int n;
	cin >> n;
	
	for(int i=2; i<=n; i++) {
		fibo.push_back( fibo[i-1]%DIV + fibo[i-2]%DIV );
		//	cout << fibo[i-1]%DIV << " + " << fibo[i-2]%DIV << endl;
	}
	cout << fibo.back() % DIV;

	return 0;
}
