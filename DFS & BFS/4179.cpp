// < ��! >  
//3888 KB	84 6ms	C++14 	2632B

#include <iostream>
#include <queue>

using namespace std;

/* ���� ���� 
DFS�� �� ��� �ð��ʰ���.  �Ұ� �������� ��ġ�� �ǵ������� �ؼ�
�� ��ü�� ��ȭ�� ũ�Ƿ� �� depth �� �����ϴ� 
BFS�� �ϴ� ���� �� ������ ���̾���. 

�׸��� queue�� �ְ� �湮 ���θ� true�� �ؾ� queue�� �ߺ��Ǽ� �ȵ��µ�
�װ� �𸣰� ó���� queue ���� ���� �� üũ�Ͽ� �޸� �ʰ��� �߻����� ��.  

���� ���� �̷� �� Ž�� �������� ��,���̳� x,y�� �̵� ��ǥ�� �迭�� ���س���
���ϰ� for���� ���� �� ���� üũ�� �ϴµ� �����¿� �̵� �� ���� üũ�� ����
if������ ó���ϰ� ���� üũ �Ŀ� ť�� �־����� �迭 ������ ������� ��Ÿ�ӿ�����
����. ������ ��Ȯ�� ĳġ���� �������� ���� �迭�� ����ϴ� ������ �������

�׸��� IMPOSSIBLE ����� Impossible�� �ؼ� Ʋ�Ƚ��ϴٰ� �߱⵵ �ߴ�... 
*/

bool* isVisited;
char** Map;
queue<int> nodeQueue;
queue<int> fireQueue; 
	
int R,C;
int Moves = 0;
 
int rdir[4] = {-1,0,1,0};
int cdir[4] = {0,-1,0,1}; 

void print_map(){
	for(size_t i=0; i<R; i++){
		for(size_t j=0; j<C; j++)
			cout << Map[i][j]<< " ";
		cout <<endl;
	}
	cout <<endl;
}

void MoveFire(){
	int steps = fireQueue.size();
	for(int i=0; i<steps; i++){
		int curpos = fireQueue.front();
		fireQueue.pop();
		int r = curpos/C;  int c = curpos%C;
		for(int i=0; i<4; i++){
			int nextr = r + rdir[i];
			int nextc = c + cdir[i];
			if (0 <= nextr && nextr < R 
			   && 0 <= nextc && nextc < C ){
				if((Map[nextr][nextc]=='.' || Map[nextr][nextc]=='J' ))	{
			 		Map[nextr][nextc] = 'F';
				 fireQueue.push(nextr*C+nextc);
				}
			}
		}
	}
}

bool MoveMan(){	
	int steps = nodeQueue.size();
	for(int i=0; i<steps; i++){
		int curpos = nodeQueue.front();
		nodeQueue.pop();
		int r = curpos/C;  int c = curpos%C;			

		// Ż�ⱸ�� ����� �� Ż��  
		if(r==0 || r==R-1 || c==0 || c==C-1){
			Moves++;
			return true;
		}
		
		for(int i=0; i<4; i++){
			int nextr = r + rdir[i];
			int nextc = c + cdir[i];
			if (0 <= nextr && nextr < R 
			   && 0 <= nextc && nextc < C 
			   && !isVisited[nextr*C+nextc]){
				if(Map[nextr][nextc]=='.')	{
			 	isVisited[nextr*C+nextc] = true;
				 nodeQueue.push(nextr*C+nextc);
				}
			}
		}
	}
	Moves++;
	return false; 
} 

bool Escape(){
	
	// Ż�ⱸ�� ������ Ż�� 
	while(!nodeQueue.empty()){
		/*-------�� ��-----*/
		// ���� ����� �����̰� ���� �ͼ� �⳪, ���� ������������ ����� �׸��� ������
		// �������� �̹Ƿ� ���� ���� �����̰� ����� �������� �Ǵ��Ѵ�. 
		MoveFire();
		if(MoveMan()) return true;
		/*------------------*/

	}
	return false;
}

int main(void){

	cin >> R >> C;
	isVisited = new bool[R*C];
	fill(isVisited, isVisited+R*C, false);
	Map = new char*[R];
	for(int i=0; i<R; i++){
		Map[i] = new char[C];
		for(int j=0; j<C; j++){
			char c;
			cin >> c;
			Map[i][j] = c;
			if(c == 'J'){
				 nodeQueue.push(i*C+j);
				 isVisited[i*C+j]=true;
			}
			else if(c=='F'){
				fireQueue.push(i*C+j);
			}
		}
	}
	
	if(!Escape()) cout << "IMPOSSIBLE"; // �̰� �ҹ��ڷ� �ߴ��� Ʋ�� 
	else cout << Moves;
	
	delete isVisited;
	delete[] Map;
	//print_map();
	return 0;
}
