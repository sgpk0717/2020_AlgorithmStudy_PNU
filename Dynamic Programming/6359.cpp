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
			jail[i] = false; // dp 다시 초기화. 
	}
	return 0;
}

/*
	다른 사람 꼼수 풀이.
	위 방법 대로 진행 후 상근이가 쓰러지면
	최종적으로 열려있는 방은 N보다 작거나 같은
	제곱수 들이다.
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
