/* ������� �Ǵ� 1937�� 
	6872KB	96ms	C++14 	2872B
		
  ���� ���� : 1) ù �õ��� �볪�� ũ��� ��ǥ�� index ���Ϳ� ������ �� ũ�⸦ �������� ������������ ������ ��,
  			  ������ζ�� �������� �����ϰ� �� ū ������ ���ʷ� �� ������ DFS�� �����Ͽ���. 
			   DFS�� ���(��ǥ) �湮 ������ ���� ��ġ�� �볪�� �纸�� �۴���, �׸��� ����� Cache ��(�̵� ���� ������ �迭)
			  ��  ���� ��ġ�� Cache ��+1 (�湮 �� +1)���� �۴��� �̴�.  ũ�ų� ������ �湮���� �� �Ȱ��� �۾��� �ߺ��ؼ� 
			  �����ϹǷ� �湮�� �ʿ䰡 ����. 
			   ���������� Cache�� �����Ͽ� ���� ���� �湮�� ���� ����ϵ��� �Ͽ���. �� ��� �ð��ʰ��� ����.
			   
			  2) ������ ���� ��� ���������� ����� �ִ밪 �����ϴ� ��� ����ص� �ð� �ʰ�.
			  (��ü ������ �׽�Ʈ ���̽� ��� �� ���� �����Ϳ����� �� ����� �� ������.)
			  
			  3) scanf, printf ��������� ���� �� ����ǰ� �ð� �ʰ�. ��ü �׽�Ʈ ���̽� ��� �ÿ��� cin, cout ����ص� �ð��� �� �Ȱɷȴµ�
			 �˰��� ���� ������ �ִ� �� ����. ������� c��� Ÿ���� ����� ��. 
		
			  4) * �׽�Ʈ ���̽��� 1���� 250000 ���� ������� ���Ե� ���� ����� 4�� ������ �ɸ��� ���� Ȯ��. 
			  	 ex) 1 2 3 .... 500
			   	   501 502... 1000
			   (��Ͱ� ������ ����(->�󸶳�?) ȣ����ٵ� �鸸�� �۾��� 1�ʶ�� ġ�� �Լ� �������� �۾��� ���̴��� ��� ȣ�� ���� ���̴��� �ؾ� �� �� ����.) 
			  
			  5) �� �켱 index ���͸� �����Ѵ� �س��� �������� ���� �Ǽ��� �־��µ� �̸� �����ص� �ð��ʰ��� ����.  
			 
			  6) * �׽�Ʈ ���̽��� 1���� 250000 ���� ������׷� ���Ե� ���� ����� ��ü�����δ� �޸� ������ ���� Ȯ��. 
				  ex) 1 2 3 .... 500
			   	  1000 999 998 ... 501  
			   	�� ��� ��Ͱ� �ִ�� ��� ȣ��� ��.  �޸����� 256M, ��� ���� �ִ� 25�� �̶�� ġ�� ���� �� �޸� ������ ���� ���� ����
			   �׸��� n�� 150�� �ǵ� 3�ʰ� �Ѿ��.	 
			   
			  7) �����غ��� �̷� ������ �ص� �湮 �ߴ� ������ ��湮�� �� ���� step�� �� ũ�� �����ؾ� �ϴ� ��ȿ������ �� �ۿ� ������... 
			     
	==================================================================================================================================================			 
			 
	�� �� :	  8)  ���� ��ư� �����ϰ� �־��� �� ����.  DFS(���ȣ��) ����� ������� �ʰ� ū ������ ������������ ��� �ϳ��� ����� Ž���ϸ鼭 
			     ĳ�ÿ� ����� �ֺ� ����� ������ Ƚ���� ����� ���� ����� ������ Ƚ���� ���ϰ� ĳ�ÿ� �������� �ݺ��ϸ� �ذ�� ���̾���.  
			    
			  9) �ٸ� ����� �ڵ带 ���� DFS�� ����ϴ°� �� ������.(30ms��) ���� �ۼ��� �Լ��� ��ȿ������ �κ��� �־��� ��. 
			  	 ���� ��ȹ���� ����� �� ������ �����ϰ� �̸� ��ȯ ������ �� ������ ����ؾ� �Ǵµ� ��� ȣ�� �� ���� Ư������ �����ؼ�
				 ������ ���� ȣ��� �Լ����� ����� �κ��� ��ȿ������ ���� ��. �Ʒ� �Լ��� ǥ��. 
*/

#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

vector<pair<int, pii> > index;
int MAP[500][500];
int Cache[250000];
int n;

int rdir[4] = {-1,1,0,0};
int cdir[4] = {0,0,-1,1};

/* DFS�� ����� �Լ� - ��ȿ�������� ¥���� */ 
//void DP(int r, int c, int val){  
//	
//	int steps = Cache[r*n+c];
//	for(size_t i=0; i<4; i++){	
//		int nextr = r+rdir[i]; int nextc = c+cdir[i]; // Check next region
//		
//		if(0<=nextr && nextr <= n-1 && 0 <= nextc && nextc <= n-1){  // In Range 
//			if(val > MAP[nextr][nextc]  && steps+1 > Cache[nextr*n+nextc]){  // �۾ƾ��� �� ��
/*-----------�߸��� �κ�------------------------------------------------------*/
//				 Cache[nextr*n+nextc] = steps+1;							  
/*----------------------------------------------------------------------------*/
////				 if(steps+1 > MAX ) MAX = steps+1; 
////				 cout << r << ", " << c << "--> " << nextr << ", " << nextc << " -> next cache : " << Cache[nextr*n+nextc] <<endl;
//				 DP(nextr, nextc, MAP[nextr][nextc]);			
//			}		
//		}
//	}
//}

int DP(int r, int c, int val){
	
	int caches[4]={0,0,0,0};
	for(size_t i=0; i<4; i++){
		int nextr = r+rdir[i];
		int nextc = c+cdir[i];
		if(0<=nextr && nextr <= n-1 && 0 <= nextc && nextc <= n-1){ 
			if(MAP[nextr][nextc] > val) caches[i] = Cache[nextr*n+nextc];
		}
	}
	
	int MAX = max(max(caches[0], caches[1]), max(caches[2], caches[3]));
	if(MAX==0)	
		return 1;
	return MAX+1;
}

bool func(pair<int,pii> a, pair<int,pii> b){
	return a.first > b.first;
}
bool func2(int a, int b){
	return a>b;
}

void print_MAP(){
	printf( "================MAP=============================\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%d ", MAP[i][j]);
		printf("\n");
	}
	printf( "================================================\n");
}

void print_CACHE(){
	printf( "===============CACHE============================\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%d ", Cache[i][j]);
		printf("\n");
	}	
	printf( "================================================\n");

}

int main(void){

//	ifstream ifs("1937tc.txt");
//	ifs >> n;
	scanf("%d", &n);

	index = vector<pair<int, pii> >(n*n);
	int p;
	
	fill(Cache, Cache+n*n, 0);

	for(size_t i=0; i<n; i++){  	// row		
		for(size_t j=0; j<n; j++){  // col
//			ifs >> p; 
			scanf("%d", &p);

		    MAP[i][j] = p;
		    index[i*n+j] = (make_pair(p , pii(i,j)));
		}
	}
	
//	ifs.close();

	sort(index.begin(), index.end(), func);

/*  DFS��� ��� (�ð� �ʰ�) 
	for(int i=0; i<n*n; i++){
		int r = index[i].second.first; 
		int c = index[i].second.second;
		if(Cache[r*n+c]==0){
			Cache[r*n+c]++;
			DP(r, c, index[i].first);
		}
	}
*/		

	for(int i=0; i<n*n; i++){
		int r = index[i].second.first; 
		int c = index[i].second.second;
		Cache[r*n+c] = DP(r, c, index[i].first);	// ū ��(�볪��) ����  
	}

	
	sort(Cache, Cache+n*n, func2);
	printf("%d", Cache[0]); 
	
	return 0;
} 
