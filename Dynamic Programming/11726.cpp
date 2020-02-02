// 1988KB, 0ms
/* 
	규칙을 찾아보면
	(2 x n)개의 직사각형을 채우는 방법의 수
	f(n)은 피보나치 수열을 따른다.
	DP를 이용한다. 
*/ 
#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 1001;
int dp[MAX];

int tiling(int n) {     // n==0일 때 채울 타일이 없으니까 방법의 수가 0 인줄 알았으나 
	if(n == 0) return 1;// 채울 방법이 없다는 경우의 수를 1 카운트 해줘야 했다. 
	if(n == 1) return 1; // base case
	if(dp[n] != -1) return dp[n]; // 검사 했던 값이면 그대로 return. 

	dp[n] = tiling(n-1) + tiling(n-2);; // dp로 계산 값 기억. 
	dp[n] %= 10007;
	
	return dp[n];
}

int main(void) {
	int n;
	cin >> n;
	fill(dp, dp+MAX, -1); // dp 초기화.
	cout << tiling(n) << endl;
	
	return 0;
}
