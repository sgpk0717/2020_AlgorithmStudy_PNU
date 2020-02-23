// 백준 11047번 < 동전 0 > 
// 메모리: 1984KB		시간:0ms 
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
			cnt += ( Money / Coin[i] );		// 몫은 사용한 동전 개수 
			Money = Money % Coin[i];		// 나머지는 남은 돈 
		}
	}
	
	return cnt;
}

int main(void) {
	input(); 
	sort( Coin.begin(), Coin.end(), greater<int>() );	// 내림차순 정렬  
	
	cout << calc();
	return 0;
}

