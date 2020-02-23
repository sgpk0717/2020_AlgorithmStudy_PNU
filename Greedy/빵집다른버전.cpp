#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int R, C;
int Answer;
vector< vector<char> > maze;
stack< pair<int,int> > tracker;

void print_maze(void) {
	for(int i=0;i<C*8;++i)
		cout << '=';
	cout << '=' << endl;
	for(int i=0;i<R;++i) {
		for(int j=0;j<C;++j) {
			cout << maze[i][j] << '\t';
		}
		cout << endl;
	}
	for(int i=0;i<C*8;++i)
		cout << '=';
	cout << '=' << endl;
}

bool is_valid(int x, int y) {
	if(!(x>=0 && x<R)) return 0;
	if(!(y>=0 && y<C)) return 0;
	return 1;
}

bool pipelining(int x, int y) {
	/* 끝까지 도달했을때 */ 
	if(y==C-1) return true; // 성공했다는 신호 
	
	//printf("\n현재위치 (%d,%d).\n",x,y);
//	print_maze();
	
	int j=y+1;
	int i;
	
	for(i=x-1;i<=x+1;++i) { // 예상경로 테스트 
		if(is_valid(i,j)) { // 좌표가 유효할때만 
			if(maze[i][j]=='.') { // 빈곳일때만 
				maze[i][j]='0'+index; // 경로 진행
				tracker.push(pair<int,int>(i,j)); // 스택에 임시 저장 
				if(pipelining(i,j,index)) { // 다음 경로로 
					return true;	// 성공시
				}
				else { 
					return false;	// 실패시  
				}
			}
		}
	}
	return false; 
}

void processing(void) {
	//cout << endl << "Processing 시작." << endl; 
	for(int i=0;i<R;++i) {
		//cout << "스택초기화." << endl; 
		while(!tracker.empty()) // 스택사용을 위해 초기화 
			tracker.pop();
		
		//printf("%d,%d에서 파이프라이닝 시작.\n",i,0);
		tracker.push(pair<int,int>(i,0));
		maze[i][0]='0'+i;
		if(pipelining(i,0,i)) { 	// 파이프라이닝 시작 
			++Answer;			// 성공시에 카운트 증가 
			//cout << "성공!" << endl; 
//			print_maze();
		}
		else {					// 실패시 
			//cout << "실패... 경로초기화" << endl;
			while(!tracker.empty()) { // 경로정보를 초기화 
				int r = tracker.top().first;
				int c = tracker.top().second;
				tracker.pop();
				
				maze[r][c] = '.';
			}
//			print_maze(); 
		}
	}
}

int main(void)
{
	cin >> R >> C;
	maze.resize(R, vector<char>(C));
	
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			cin >> maze[i][j];
	
//	print_maze();
	
	processing(); 
	
	cout << Answer << endl;
	
	return 0;
}
