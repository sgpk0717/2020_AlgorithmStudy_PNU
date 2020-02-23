// ���� 11047�� < ���� 0 > 
// �޸�: 1984KB		�ð�:0ms 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int CoinType_N, Money;
vector < int > Coin;

void input() {
	cin >> CoinType_N >> Money;
	for(int i=0; i<CoinType_N; i++) {
		int coin;
		cin >> coin;
		Coin.push_back( coin );
	}
}

int calc() {
	int cnt = 0;
	
	for(int i=0; i<CoinType_N && Money>0; i++) {
		if( Coin[i] <= Money ) {
			cnt += ( Money / Coin[i] );		// ���� ����� ���� ���� 
			Money = Money % Coin[i];		// �������� ���� �� 
		}
	}
	
	return cnt;
}

int main(void) {
	input(); 
	sort( Coin.begin(), Coin.end(), greater<int>() );	// �������� ����  
	
	cout << calc();
	return 0;
}

