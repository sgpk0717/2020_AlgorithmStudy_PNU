// 1988KB, 0ms
/* 
	��Ģ�� ã�ƺ���
	(2 x n)���� ���簢���� ä��� ����� ��
	f(n)�� �Ǻ���ġ ������ ������.
	DP�� �̿��Ѵ�. 
*/ 
#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 1001;
int dp[MAX];

int tiling(int n) {     // n==0�� �� ä�� Ÿ���� �����ϱ� ����� ���� 0 ���� �˾����� 
	if(n == 0) return 1;// ä�� ����� ���ٴ� ����� ���� 1 ī��Ʈ ����� �ߴ�. 
	if(n == 1) return 1; // base case
	if(dp[n] != -1) return dp[n]; // �˻� �ߴ� ���̸� �״�� return. 

	dp[n] = tiling(n-1) + tiling(n-2);; // dp�� ��� �� ���. 
	dp[n] %= 10007;
	
	return dp[n];
}

int main(void) {
	int n;
	cin >> n;
	fill(dp, dp+MAX, -1); // dp �ʱ�ȭ.
	cout << tiling(n) << endl;
	
	return 0;
}
