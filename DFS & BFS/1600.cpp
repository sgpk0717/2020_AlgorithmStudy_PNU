// < ���� �ǰ��� ������ > 
//	4872KB	100ms	C++14 	2353B

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* ��������
 ���� ������ �����ؼ� ������ Ǯ�� ���ϱ� ó���� ������ ����������. 
 ��ó�� K�� �̵��ϴ� ���� ��� �����ϴ��ĸ� �����ϴٰ� BFS�� Ž���� �� �� ��带
 ť�� ���� �� K�� �Һ��� ��� ���� ��忡�� �Һ��� K�� +1�ؼ� �����ϴ� ������ 
 ����� ���� K������ ������ ť�� ���� �ʵ��� �ߴ�.
  -> queue< pair <int,int > >�� ( ��ǥ����, K�� )�̴�.
 
  �ٵ� Ʋ�ȴ��ؼ� �����غ��ϱ�  ���������� ����(���� �̵�) �� ����(�� ĭ �̵�)�� ����  
  ��带 �湮�ϱ� ������  �ش� ��带 �湮�� �� j-s-j-s(K=2)  s-s-s-s-s(K=0).. �̷� ������ ���� ��带 �湮�� �� �ִ�. 
  ���ڿ��� �湮���θ� üũ�ع����� ���� ��(K) �� ������ �����Ƿ� ���� �Һ� ������ ���� ��ΰ� �پ��ѵ�
  �װ͵��� ���ƹ�����. �׷��� �湮 ���� üũ �� �� K�� ������ ���� �޸��ϱ� ���� K������ bool ���͸� ��ҷ� ���� ���ͷ� �湮 ���θ� üũ����.
  
  �ٵ��� Ʋ���� �޸� �ʰ��ؼ� ������ ���� ���͸� ������ �ϳ��� ������ �غôµ��� ����� �ȵǱ淡 �ҽ��� �ٽú���
    	if(!Visited[nextr*W + nextc][Ks+1] && Map[nextr][nextc]==0 ) �̺κп��� Ks+1 �� ����� �ϴµ� Ks �� üũ�ߴ� ���̾
  �̺κ��� �����ϴ� ����Ǿ���. Ȥ�� ���� ���ܰ� ���� ���͸� ����� �������� ����� �ȴ� �ٵ� �޸𸮴� 1.5��, �ð��� 2������ �� ���.
   BFS���� ó���� ���� �迭�� �� �� ���� �ص� ���ε��� ó���ϹǷ�  �ð��� 2�質 �� ���� �����ٵ� �޸� �Ҵ� ������ �ð��� �� ��� �ɱ�?
   �ƴϸ� �迭�� �ϳ��� ����ϸ� �޸� ���ÿ��� ó���� �� locality �� �����ؼ� �׷�����.. ��Ȯ�� ������ �𸣰ڴ�.
  
*/

vector<bool>* Map;
//vector< vector<bool> > stepVisited;
//vector< vector<bool> > jumpVisited;
vector<vector<bool> > Visited;
queue< pair<int,int> > posQueue;
//         ��ǥ���� , K ��   

int K,W,H; 
int Move=0;

int rdir[12] = { 0, -1, 0, 1, -1, -2, -2, -1, 1 , 2 , 2 , 1};
int cdir[12] = { -1, 0, 1, 0, -2, -1,  1,  2,-2, -1,  1,  2};

//void print(){
//	for(size_t i=0; i<H; i++){
//		for(size_t j=0; j<W; j++){
//			cout  <<  Map[i][j] <<  " ";
//		}
//		cout <<endl;
//	}	
//}

int BFS(){
	int pos;

	posQueue.push(make_pair(0,0));	
	for(int i=0; i<=K; i++){
//		stepVisited[0][i] = true;	
//		jumpVisited[0][i] = true;	
		Visited[0][i]= true;
	}
	
	while(!posQueue.empty()){
//		cout << "-----------MOVE : " << Move << "-----------------" <<endl;
		int queueSize = posQueue.size();
		for(int p=0; p<queueSize; p++){
			pos = posQueue.front().first;
			int Ks = posQueue.front().second;	
			if(pos == W*H-1 && Ks <= K) 
				return Move;
			int r = pos/W; int c = pos%W; 	
//			cout << "r : " <<r << " c : " << c << " K : " << Ks << endl;	
			posQueue.pop();			
			for(int i=0; i<12; i++){
				
				int nextr = r+rdir[i]; int nextc = c+cdir[i];
				// In Range
				if( 0<= nextr && nextr <= H-1 && 0 <= nextc && nextc <= W-1){
					
					if( i>=4 && Ks < K ){
						if(!Visited[nextr*W + nextc][Ks+1] && Map[nextr][nextc]==0 ){ // ���⼭ �湮 üũ�� �� Ks+1�� ���߾���.. 
//							cout<< "JUMP & PUSHING " << nextr << ", " << nextc <<endl; 
							posQueue.push(make_pair(nextr*W+nextc, Ks+1));
							Visited[nextr*W+nextc][Ks+1] = true;
						}
					}
					else if( i< 4 ){
						if(!Visited[nextr*W + nextc][Ks] && Map[nextr][nextc]==0 ){
//							cout<< "STEP & PUSHING " << nextr << ", " << nextc <<endl; 
							posQueue.push(make_pair(nextr*W+nextc, Ks));
							Visited[nextr*W+nextc][Ks] = true;
						}
						
					} 
					
				}
			}	
		}
		Move++;
	}
	
	return -1;
}

int main(void){
	cin >> K >> W >> H;
	Map = new vector<bool>[H];
//	stepVisited = vector< vector<bool> >(W*H, vector<bool>(K+1,false));
//	jumpVisited = vector< vector<bool> >(W*H, vector<bool>(K+1,false));
	Visited = vector< vector<bool> >(W*H, vector<bool>(K+1,false));
	for(int i=0; i<H; i++){
		Map[i] = vector<bool>(W);
		for(int j=0; j<W; j++){
			bool b;	 cin >> b;	Map[i][j] = b;
		}
	}
	
	cout << BFS();
	
	return 0; 
}
