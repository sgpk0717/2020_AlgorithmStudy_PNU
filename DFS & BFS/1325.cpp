// < ȿ������ ��ŷ > 
//3196KB	3976ms	C++17 	1797B

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*���� ���� 
 dfs�� ����ؼ� �����ذ��� �õ��ߴ�.
 ������ dfs�� �� ��忡�� ���� �� ������� �ʰ� �߰��� cut �ǰ� �ϱ� ���ؼ� ���� dfs������ �̿��Ϸ� ������
 �����غ��� ���� ������ ����  �ִ���. ������ ����� ���� ���� ��� ������ ���� ��ŷ ���� ���ϴµ�, 
 ������ �ϳ��� �ƴϰ� ���� �����ϴ� �׷��� ������ �� �־ �ǰ� ����������. �׷��� �ᱹ �� ��帶�� dfs�� �����ϱ�� ����.
 
 �׷��� �� ��帶�� �Ϲ����� dfs������� ��ŷ ������ ��� ���� üũ�� �� �湮 ���� �迭�� ���� �����ϴ� ������� �ߴ�.
 �ٵ� �ð��ʰ��� ����. �׷��� �ð��� �ٿ������� �̷����� �õ��ߴµ� ó������ ���Ϳ� ��ŷ ������ ��� ���� dfs�� üũ�ϴ� ����ȣ�� 
 pair �� ������ �������� sorting �� �� ���� ���� ��ŷ�ϴ� ��带 ����߾���.
 
 ���� ���� ���� �ð��� ���̱� ���� �ϴ� ����ȣ�� ���� �ͺ��� dfs�� ���ȴ�. �׸��� MaxNum (�ִ� ��ŷ ��� ��)�� �����ϰų� ���� ������ 
 stack�� �����ߴ�. �׷��� ���������� (��ŷ ��� ��, ����ȣ)�� stack�� ��ŷ ��� ���� ���� �ͺ���  
 stack�� top���� �Ʒ���  ����ȣ�� ���� �������� ������״ϱ� ��ŷ ��� ���� �ٲ� ������ �ϳ��� ������ ��� ��ȣ�� ����ϸ� ��� ��ȣ��
 ������������ ��� �� ��. �ٵ� �̷��� ó���� �ð��ʰ��� ����.. 
  
  <�̻�����?> 
    �ص��ص� ����� �ȵǱ淡 
	C++14 ��� �� continue ����ϸ� �ð� �ʰ��� ���� 
	C++17�� ����ؼ� continue�� �Ⱦ��� ����Ǿ���. continue�� ���� ���� �� ���� �ɷ�����
	����ȴ�.
	�ٽ� C++14�� ����ؼ� �� �� �غ���?? �ȴ�?? ������ �𸣰���.
	�����δ� �ణ�� �ð����̰� �� ms �ȳ���.
	
	* ������ ������ �ð��� ���̰� �� ���µ� ������ ���� ���ư��� �׷� �� 
*/ 

int N,M;
vector<int>* Graph;
stack< pair<int,int> > Answer;
vector<bool> Visited;
int Num = 0;
int MaxNum = 0;


void print_Graph(){
	for(int i=1; i<N+1; i++){
		cout << i << ": ";
		for(int j=0; j< Graph[i].size(); j++){
			cout << Graph[i][j] << " ";
		}
		cout <<endl;
	}
}

  
void Hack(int i){
	Num++; 
//	vector<int> ERs = Graph[i];
	for(size_t j=0; j<Graph[i].size(); j++){
		int ER = Graph[i][j];
			if( !Visited[ER-1]) {
			Visited[ER-1] = true;
			Hack(ER);
		}
	}
}



int main(void){
	cin >> N >> M;
	Graph = new vector<int>[N+1];
//	for(size_t i=1; i<=N; i++)
//		Answer.push_back(pair<int,int>(i,0));
	
	Visited = vector<bool>(N,false);
	for(size_t i=0; i<M; i++){
		int ER, EE;
		cin >> ER >> EE;
		Graph[EE].push_back(ER);
	}
	
	for(size_t i=N; i>=1; i--){
//		cout << "i : " << i << " ,size : " << Graph[i].size() <<endl; 
		if(Graph[i].size() > 0) {
			fill(Visited.begin(), Visited.end(), false);
			Visited[i-1] = true;
			Hack(i);
//		cout << "Num :  " << Num <<endl;
			if(Num >= MaxNum){
				MaxNum = Num;
				Answer.push(make_pair(Num, i));
			}	
		
			Num=0;
		}	
	}
	
//	print_Graph();
	
//	sort(Answer.begin(), Answer.end(), func);
	
//	for(size_t i=0; i<N; i++){
//		cout<< Answer[i].first<< " " <<Answer[i].second <<endl;
//	}
//	cout << MaxNum <<endl;
	int StackSize = Answer.size();
	for(size_t i=0; i<StackSize; i++){
//		cout << "Stack size : " << Answer.size() <<endl;
		pair<int,int> Top = Answer.top();
//		cout << "first : " << Top.first <<endl; 
		if(Top.first != MaxNum) break;
//		cout << "second : " << Top.second <<endl; 
		cout << Top.second <<" ";
		Answer.pop();
	}
	
	return 0;
}
