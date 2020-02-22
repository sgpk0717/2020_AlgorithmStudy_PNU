/*  11047 ���� 0 
	1984KB	0ms	C++14
  	
	��ġ�� �־��� ������� �ּ����� ����� ������ ���� ä���. 
	�׸��� �˰��� ���  
	
	https://www.acmicpc.net/problem/11047 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int M[10];
int P,N;

int main(void){
	int ans = 1<<30;
	cin >> N >> P;  // ���� ���� ������ ��  
	for(int i=0; i<N; i++)
		cin >> M[i]; // ������ ��ġ�� 
	
	for(int i=0; i<N; i++){
		int a = 0;
		int p = P;
		for(int j=i; j>=0; j--){
			a += p/M[j];
			p = p%M[j];
		}
		ans = min(ans, a);	
	}
	
	cout << ans;
	return 0;
}
