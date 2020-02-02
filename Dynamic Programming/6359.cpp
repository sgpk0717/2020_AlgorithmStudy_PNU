// 1984KB, 4ms
#include <iostream>
using namespace std;

constexpr int MAX = 101;
bool jail[MAX] = {false,}; // false: closed, true: opend

void wisky(int r, int k) { // lock or unlock.
	for(int i=r; i<=k; i=i+r) {
		jail[i] = !jail[i];
	}
}

int escape(int k) {
	for(int r=1; r<=k; ++r) { // Round.1~k 
		wisky(r, k);
	}
	int cnt = 0;
	for(int i=1; i<=k; ++i) {
		if(jail[i] == true) ++cnt;
	}
	return cnt;
}

int main(void) {
	int T, n;
	cin >> T;
	for(int t=0; t<T; ++t) {
		cin >> n;
		cout << escape(n) << endl;
		for(int i=1; i<=n; ++i)
			jail[i] = false; // dp �ٽ� �ʱ�ȭ. 
	}
	return 0;
}

/*
	�ٸ� ��� �ļ� Ǯ��.
	�� ��� ��� ���� �� ����̰� ��������
	���������� �����ִ� ���� N���� �۰ų� ����
	������ ���̴�.
	#include<stdio.h>
	int main() {
	int i, t, n; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 1; i*i <= n; i++);
		printf("%d\n", i-1);
	}
    return 0;
} 
*/
