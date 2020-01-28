#include <iostream>
#include <vector>
using namespace std;

/*
	���� 1780�� ������ ����.
	�޸�: 37052KB		�ð�: 484ms
	���� �ڵ忡��  cin/cout�� scanf/printf�� �ٲٰ�,
	�������� for������ �ϳ��ϳ� ����ϴ°ɷ� �ٲٴϱ�
	�ð��� 1128ms���� 484ms�� �����. 
*/

vector< vector<int> > Paper;
int result[3];	// result[n+1]: n�� ���� ���� 
int Maxsize;	// 1 ~ 3^7(�� 2000) 

void inputData() {
	scanf("%d", &Maxsize);
	Paper.resize(Maxsize);
	
	for(int i=0; i<Maxsize; i++) {
		int tmp;
		for(int j=0; j<Maxsize; j++) {
			scanf("%d", &tmp);
			Paper[i].push_back(tmp);
		}
	}
}

bool is_paper( int s_x, int s_y, int e_x, int e_y ) {
	int standard = Paper[s_x][s_y];

	for(int x=s_x; x<=e_x; x++) {
		for(int y=s_y; y<=e_y; y++) {
			if( Paper[x][y] != standard ) { 
				return false; 
			} 
		}
	}
	return true;
}

void solve( int s_x, int s_y, int size ) { 
	if( size == 1 ) {
		int num = Paper[s_x][s_y];
		result[num+1]++ ;
		return ;
	} 
	
	int e_x = s_x + size - 1;	int e_y = s_y + size - 1;
	int standard = Paper[s_x][s_y];
	if( is_paper( s_x, s_y, e_x, e_y ) ) {
		result[standard+1]++ ;
		return ;
	} 
	
	for( int i=s_x; i<(s_x+size); i+=(size/3) ) {
		for(int j=s_y; j<(s_y+size); j+=(size/3) ) {
			solve(i, j, size/3);
		}	
	}
}

int main(void) {
	inputData();
	solve( 0, 0 , Maxsize);
	
	printf("%d\n%d\n%d", result[0], result[1], result[2]);
	
	return 0;
}
