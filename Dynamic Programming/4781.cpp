// 2248KB, 820ms
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

constexpr int MAX_c = 5001;
constexpr int MAX_m = 10001;

int dp[MAX_m]; // 가격(인덱스)에 따라 칼로리(값)이 정해짐. 
pair<int, int> price[MAX_c];
int n; // candy 종류 수. 

int candy(int money) {
	if(money == 0) return 0; // 0원이면 0칼로리. 
	if(dp[money] != -1) return dp[money];  // cache

	int result = 0;
	for(int i=0; i<n; ++i) {
		// 돈이 부족하지 않으면
		if(money - price[i].second >= 0)
			result = max(result, candy(money - price[i].second)
					+ price[i].first);
	}
	dp[money] = result;
	return result;
}

int main(void) {
	int c;
	double m, p;
	while(true) {
		cin >> n >> m;
		if(n==0 && m==0.0) break; // escape
		fill(dp, dp+MAX_m, -1); // cache 초기화. 
		
		for(int i=0; i<n; ++i) { // Input
			cin >> c >> p;
			p = (int)(p*100+0.5); // 자연수 만들기. (괄호에 주의해야함!! 에러 찾는데 고생함.) 
			price[i].first = c; // cal
			price[i].second = p; // price
		}
		m = (int)(m*100+0.5);
		cout << candy(m) << endl;
	}
	
	return 0;
}
