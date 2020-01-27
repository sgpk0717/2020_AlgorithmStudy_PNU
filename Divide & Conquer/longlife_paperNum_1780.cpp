#include <iostream>
#include <fstream>
#include <vector>
#include <numeric> 

using namespace std;

typedef vector<int> line;

int NumZero, NumOne, NumMinus, val_th;

void find_paperNum(vector< line >& paper, int row, int col, int sz)
{
	int is_NumZero = 0*sz*sz;			// 0 ���� �� 
	int is_NumOne = 1*sz*sz;			// 1 ���� �� 
	int is_NumMinus = val_th*sz*sz;	// -1 ���� �� 
	vector<int> sum_line;
	for(int i=row;i<row+sz;++i)
		sum_line.push_back(accumulate(paper[i].begin()+col,paper[i].begin()+col+sz,0));

	int sum_val = accumulate(sum_line.begin(),sum_line.end(),0);
	
	if(sum_val == is_NumZero){ 			// 0 ������ ��� 
		NumZero++;
		return ;
	}
	else if(sum_val == is_NumOne){		// 1 ������ ��� 
		NumOne++;
		return ;
	}
	else if(sum_val == is_NumMinus){	// -1 ������ ���
		NumMinus++;
		return ;
	}
	else{
		sz/=3;
		find_paperNum(paper,row,col,sz);				// 1) ��, �� 
		find_paperNum(paper,row,col+sz,sz);				// 2) ��, �߰� 
		find_paperNum(paper,row,col+(2*sz),sz);			// 3) ��, ���� 
		find_paperNum(paper,row+sz,col,sz);				// 4) �߰�, ��
		find_paperNum(paper,row+sz,col+sz,sz);			// 5) �߰�, �߰� 
		find_paperNum(paper,row+sz,col+(2*sz),sz);		// 6) �߰�, ���� 
		find_paperNum(paper,row+(2*sz),col,sz);			// 7) �Ʒ�, ��
		find_paperNum(paper,row+(2*sz),col+sz,sz);		// 8) �Ʒ�, �߰� 
		find_paperNum(paper,row+(2*sz),col+(2*sz),sz);	// 9) �Ʒ�, ���� 
		return ;	
	}
}

int main(void)
{
	int N, tmp;
	cin >> N;
	val_th = N*N + 1;
	vector< line > paper(N,line(N));
	for(int i=0;i<paper.size();++i){
		for(int j=0;j<paper[i].size();++j){
			cin >> tmp;
			if(tmp == -1)
				paper[i][j] = val_th;
			else
				paper[i][j] = tmp;
		}
	}
			
	find_paperNum(paper,0,0,N);

	cout << NumMinus << endl;
	cout << NumZero << endl;
	cout << NumOne << endl;
	 
	return 0;
}
