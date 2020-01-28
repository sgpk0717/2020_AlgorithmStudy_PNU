// ���� 1074  [Z] 	�޸�: 2168KB	�ð�: 0ms 
#include <iostream>
#include <math.h>
using namespace std;

int count;	// ��� 

void solve(int abs_i, int abs_j, int size ) {
	if( size == 1 )	{ return ; }
	int half = size/2;
	int order = 0;	// 4ĭ�� ���° ĭ����(0,1,2,3) 
	
	bool i_smaller = abs_i < half;
	bool j_smaller = abs_j < half;
	
		 if(  i_smaller &&  j_smaller )	{ order = 0; }
	else if(  i_smaller && !j_smaller )	{ order = 1; }
	else if( !i_smaller &&  j_smaller ) { order = 2; }
	else if( !i_smaller && !j_smaller ) { order = 3; }
	
	count += (half * half) * order;	// ���� ĭ�� ùĭ �������� ���� ���� 
	
	cout << "\nsize: " << size << endl;
	cout << "order: " << order << endl; 
	cout << "count: " << count << endl;
	// ù ĭ�� (0,0)�� �ǵ��� ������� �ε����� ���� 
	int rel_i = ( i_smaller ? abs_i : abs_i-half ) ;
	int rel_j = ( j_smaller ? abs_j : abs_j-half ) ;
	solve( rel_i, rel_j, half );
}

int main(void) {
	int N, abs_i, abs_j;
	scanf("%d%d%d", &N, &abs_i, &abs_j);
	solve( abs_i, abs_j, pow(2,N) );
	cout << count;
	return 0;
}

