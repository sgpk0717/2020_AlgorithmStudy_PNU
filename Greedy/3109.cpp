/* 	3109 ����  
	6868KB	92ms	C++14
	
	 2���� �迭�� ���� �� ����� ������ ����� dfs�� ����� �ִ��� ���� ���鵵�� �Ѵ�. 
				�� �࿡�� ����ؼ� �湮�ߴٰ� �ᱹ ���� �ϼ����� ���ߴٸ� �� ��δ� �Ʒ� �࿡�� ��θ� Ž���� �� ���� �湮�� �ʿ䰡 ��������.
				(�׸��� �˰������� ������ �� �ִ�.)
				  
	���� ���� : 2���� �迭�� �湮 ��ġ�� ǥ���� �� ���� ������ ������ +48�� �� (0~9)���ڸ� ��Ÿ���� ���ڷ� ǥ���ϰ� �;�����
	 		    R���� Ŀ���� char ������ �Ѿ�� �ȴ�. �ð��� ���� �ɸ����� char������ �Ѿ�� �ᱹ ���� ������ ��찡 �־��µ�
				�����Ϸ����� ��� ó���Ǵ� ���� �ñ��ϴ�.   
	
	
	https://www.acmicpc.net/problem/3109 
*/

#include <iostream>
//#include <fstream>

using namespace std;
typedef pair<int,int> pii;

int R,C,Answer = 0;
char place[10000][500];
int dir[3] = {-1,0,1};

bool inRange(int r){
	return (0<=r && r<=R-1);
}

bool Search(int r, int c){
	if(c==C-1) return true;
	
	bool Arrival = false;
	for(size_t n=0; n<3; n++){
		int D = dir[n];
		if(inRange(r+D)){
 			 if(place[r+D][c+1]=='.'){
				place[r+D][c+1] = 'x'; // N+48 �� �ٲٸ� �ð��� �ξ� �����ɷ��� ���. 
				Arrival = Search(r+D, c+1);
				if(Arrival) break;
			}
		}		
	}
	return Arrival;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> C;
// 	ifstream ifs("3109tc.txt");
//	ifs >> R >> C;
 	
	for(size_t i=0; i<R; i++){
		for(size_t j=0; j<C; j++)
			cin >> place[i][j];
//			ifs >> place[i][j];
	}
//	ifs.close();

	for(size_t i=0; i<R; i++){
		if(Search(i,0)) 
			Answer++;
	}
	
	cout << Answer;
	
	return 0;
}
