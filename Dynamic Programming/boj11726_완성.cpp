// ���� 11726�� < 2xn Ÿ�ϸ� >
// �޸�: 1984 KB		�ð�: 0 ms
#include <iostream>
#include <vector>
#define DIV 10007
using namespace std;
// i-1�� i-2 �����Ҷ� �ȳ������� �����÷ο� �߻��ؼ� Ʋ�Ⱦ��� 
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
