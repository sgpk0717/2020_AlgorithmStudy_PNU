/* 	2875 ��ȸ or ����  
	1980KB	0ms	C++14 358B
 	
 	���л�, ���л�, �ʿ� ���� ���� �־����� 
	2���� ���л�, 1���� ���л��� ���� �̷�� �ϴ� ���߿� ��ü���� ���� ����ŭ ������ �Ѵ�	
	�� �� ���� �� �ִ� �ִ� ���� ���� ���Ѵ�.	
	���л�, ���л�, ���� ���� ��쿡 ���� ���̽��� ������ �ذ�  
		
 	https://www.acmicpc.net/problem/2875 
*/
#include <iostream>

using namespace std;

int main(){
	int W, M, K; // ��, ��, ���� �� 
	cin >> W >> M >> K;
	
	int t = min(W/2, M); 
	int r = (W - t*2) + (M - t);
	
	if(r < K) {
		K -= r;
		int kn = K/3;	
		if(K%3 > 0)		
			 t -= (kn+1);
		else t -= kn;
		if(t<=0) t = 0;	
	}
	
	cout << t;	
		
	return 0;
	
} 
