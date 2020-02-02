// 2248KB, 820ms
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

constexpr int MAX_c = 5001;
constexpr int MAX_m = 10001;

int dp[MAX_m]; // ����(�ε���)�� ���� Į�θ�(��)�� ������. 
pair<int, int> price[MAX_c];
int n; // candy ���� ��. 

int candy(int money) {
	if(money == 0) return 0; // 0���̸� 0Į�θ�. 
	if(dp[money] != -1) return dp[money];  // cache

	int result = 0;
	for(int i=0; i<n; ++i) {
		// ���� �������� ������
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
		fill(dp, dp+MAX_m, -1); // cache �ʱ�ȭ. 
		
		for(int i=0; i<n; ++i) { // Input
			cin >> c >> p;
			p = (int)(p*100+0.5); // �ڿ��� �����. (��ȣ�� �����ؾ���!! ���� ã�µ� �����.) 
			price[i].first = c; // cal
			price[i].second = p; // price
		}
		m = (int)(m*100+0.5);
		cout << candy(m) << endl;
	}
	
	return 0;
}
