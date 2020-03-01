/* 4991 �κ� û�ұ�
	1984KB	44ms	C++14 
	
 	 �ߺ��湮�� ����ϴ� 1x1 ĭ���� �̷���� �������� û�ұⰡ �־��� �ʱ� ��ġ���� ����ؼ� ������ ĭ�� ��� �湮�ϴµ���
	�ʿ��� �ּ� �̵�Ƚ���� ���ϴ� ����.
	
	 û�ұ� �ʱ� ��ġ�� ������ ������ Graph�� vertex�� �����ϰ� ��� vertex���� bfs�� ���� ���� �ּ� �̵� Ƚ���� ����ġ(weight)�� ���
	������ edge�� �ξ���. �� vertex���� �ʱ⿡ testcase�κ��� �Է°��� ���� �� pair<int,int> vertex[10] �迭�� ����ǰ� 
	�� �迭�� index���� ������ ���� ���� ������ �湮������ ��� �� vertex�� ��� �湮�ϴµ� �ʿ��� �ּ� �̵�Ƚ���� ���Ͽ���.
	�� �� �ּڰ� int m(getShortestPath �Լ�) �� �ξ� �� �������� �湮�ϴٰ� �̵�Ƚ���� �ּڰ��� �Ѿ ������ ��ٷ� ���� ������ ����
	�Ѿ���� �Ͽ� �ð��� ������״�.  
	  
	 makeGraph( int Graph[10][10]�� ���� �����ϴ� �Լ� )�� ����� false �� ��, �� �湮���� ���ϴ� ������  ĭ�� �ִ� testcase����
	vn(û�ұ� �ʱ� ��ġ�� ������ ĭ�� ���� - ������ Graph�� vertex ���� �ʱ�ȭ ���� �ʾƼ� Runtime Error�� �߻��߾���.
	
	 �ع����� �ذ��� �ٸ� ������� �˰��� ������ ��Ʈ����ŷ�� �߰��س��� �� ���� ��Ʈ����ŷ�� �̿��� �޸𸮿� �ð��� �����ų�� ���� �� ����!  
*/

#include <iostream>
#include <algorithm>
#include <queue>

#define r first
#define c second

using namespace std;

typedef pair<int,int> pii;

int Graph[10][10];
char Map[20][20];
pii vertex[10];

int rdir[4] = {-1,0,1,0};
int cdir[4] = {0,-1,0,1};

int w=0, h=0; //c, r
int vn = 1;

int* visitOrder;

bool inRange(int r, int c){
	return  ( (0 <= r) && (r < h) && (0 <= c) && (c < w) );
}

int getWeight(pii from, pii to){ // bfs�� ���� Graph�� ����
	int dist = 0;
	bool visited[20][20];
	
	for(size_t i=0; i<h; i++){
		for(size_t j=0; j<w; j++)
		 	visited[i][j]=false;
	}
	
	visited[from.r][from.c] = true;
	queue<pii> vQueue;
	
	for(size_t i=0; i<4; i++){
		int nextr = from.r+rdir[i];
		int nextc = from.c+cdir[i];
		if(inRange(nextr, nextc)){
		  if( Map[nextr][nextc] != 'x'){
				vQueue.push(pii(nextr,nextc));
				visited[nextr][nextc] = true;
			}
		}
	}
	
	while(!vQueue.empty()){
	 	dist++;
	 	int qSize = vQueue.size();
	 	for(size_t i=0; i<qSize; i++){
	 		pii cv = vQueue.front();
	 	
		 	if(cv == to) 		//Ż������  
			 	return dist;
		
			for(size_t i=0; i<4; i++){
				int nextr = cv.r+rdir[i];
				int nextc = cv.c+cdir[i];
				if(inRange(nextr, nextc) ){
					 if( Map[nextr][nextc] != 'x' && !visited[nextr][nextc]){
						vQueue.push(pii(nextr, nextc));
						visited[nextr][nextc] = true;
					}
				}
			}
			vQueue.pop();	
		 }
	} 
	return -1;
}

bool makeGraph(){
	for(size_t i=0; i<vn; i++){
		for(size_t j=i; j<vn; j++){
			if(i==j) 
				Graph[i][j] = 0; 
			else{
				Graph[i][j] = Graph[j][i] = getWeight(vertex[i], vertex[j]);
				if(Graph[i][j]==-1) {
					return false;
				}
			}

		}
	}
	
	return true;
}

int getShortestPath(){
	int m = 1<<10;
	do{
		int preV = 0;
		int sumW = 0;
		size_t i;
		for(i=0; i<vn-1; i++){
				int curV = visitOrder[i];
				sumW += Graph[preV][curV];
				preV= curV;
				if(sumW > m) break;
		}
		if(i!=vn-1) continue;
		m = min(m, sumW);
	}while(next_permutation(visitOrder, visitOrder+vn-1));
	
	return m;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	while(true){   
		cin >> w >> h;
		if(w==0 && h==0) break; // ��������  
		
		for(size_t i=0; i<h; i++){
			for(size_t j=0; j<w; j++){
				cin >> Map[i][j];
				if(Map[i][j] == '*'){
					vertex[vn] = pii(i,j);
					vn++;
				}
				else if(Map[i][j]=='o')
					vertex[0] = pii(i,j);
			}
		}

	 	if(!makeGraph())	// ������ �� ���� ĭ�� �ִ� ���  
		  cout << -1 <<endl;	
		  
		else{
		 	visitOrder = new int[vn-1]; // ĭ �湮 ���� �迭  
		 	for(size_t i=0; i<vn-1; i++)
		 		visitOrder[i] = i+1;
		
			cout << getShortestPath() <<endl;
			delete visitOrder;
		}
	
		vn = 1;
	}
	
	return 0;
} 
