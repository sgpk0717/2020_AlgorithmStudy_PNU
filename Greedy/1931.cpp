/* 	1931 ȸ�ǽ� ����
	2764KB	32ms	C++14	
	
	�ð��� �־��� ȸ�ǵ��� ��ġ�� �ʰ� �ִ�� ��ġ�ϴ� ����.
	 
	���� �� ������ �ð��� ��������, ���� �� ���۽ð� ������������ ������. 
	ȸ�� ���� �ð��� ���� ȸ���� ������ �ð����� ���ų� ũ�� �ȴ�.  
	
	���۽ð� �켱���� �������� ������ �ڵ嵵 �ð��� �Ȱ��� �ɸ���.  
	
	https://www.acmicpc.net/problem/1931 
*/

#include <iostream>
#include <algorithm>

#define b first
#define e second

using namespace std;
typedef pair<int,int> pii;
pii data[100000] ;
int n;

bool func(pii x, pii y){
	if(x.e < y.e) return true;
	else if(x.e == y.e) return x.b < y.b;
	return false;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); 

	int b,e;
	int m = 1;  // �ִ� ȸ�� �� 
	cin >> n;
	
	for(size_t i=0; i<n; i++){
		cin >> b >> e;
		data[i] = pii(b,e);
	}
			
	if(n==1){
		cout << 1;
		return 0;
	}
		
	sort(data, data+n, func); // �ð� ������ ����  
	
	int ep = data[0].e;
	for(size_t i=1; i<n; i++){
		if(data[i].b >= ep){	
			m++;
			ep = data[i].e;
		}
	}
	cout << m;
	
	return 0;
}
