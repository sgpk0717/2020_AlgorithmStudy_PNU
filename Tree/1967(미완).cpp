/* 1967�� Ʈ���� ���� 
	�������κ��� Ÿ�� �ö󰡸鼭 �� ����� ���� �� �ִ� ����ġ ���� �� ���ϴ� �� O(N)	 
	�ٽ� Ÿ�� �������鼭 �� ��忡���� �ִ� ����ġ �� ���ϴ� �� O(N)  (���� �� �� �����ؼ� ����ġ �հ� �ڽ� ����� �ִ� ����ġ ���� ���Ѵ�)  
	Ʋ���� ���� ���ذ�
	https://www.acmicpc.net/problem/1967 
 
*/
 
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
 
int N;
struct node{
	int num = 1; 			// ��� ��ȣ 
	node* p = nullptr;  // �θ� ��� ������  
	vector<node*> c;    // �ڽ� ��� ������ ���� 
	vector<int> g;	    // �ڽ� ������ ����ġ 
	
	node(){}			// ����Ʈ ������ 
	
	node(node* pa, int num, int val){  // �θ��� ������ ,  ��� ��ȣ, ����ġ 
		this->p = pa;
		this->num = num;
		pa->g.push_back(val);
	}
};

map<int, node> Nodes;			// ��ü ��� 
map<int, int> maxBranch;      // �� ��忡�� �ڽ������� �ִ� ����ġ 


void print_tree(){
	map<int,node>::iterator it;

	for(it=Nodes.begin(); it!=Nodes.end(); it++){
		cout << "------------------------------"<<endl;
		cout << "NUM : " << it->first<<endl;
		node& n = it->second;
		if(n.p!=nullptr)
			cout << "PARENT : " <<  n.p->num <<endl;
		cout << "CHILDREN : ";
		for(size_t i=0; i<n.c.size(); i++)
			cout << n.c[i]->num << " ";
		cout <<endl;
		cout << "WEIGHTS : ";
		for(size_t i=0; i<n.g.size(); i++)
			cout << n.g[i]<< " ";
		cout <<endl;
	}
}

// maxBranch�� �ϼ���Ų�� 
void getMaxBranchWeight(){	
	map<int,node>::reverse_iterator rit;
	for(rit = Nodes.rbegin(); rit!=Nodes.rend(); rit++){
		int m = 0;
		node& n = rit->second;
		for(size_t i=0; i<n.g.size(); i++){
			m = max(m, n.g[i]+maxBranch[n.c[i]->num]);	
		}
		maxBranch[n.num] = m;
	}
}

int getLongestPath(){
	int m = 0;
	map<int,node>::iterator it;
	it = Nodes.begin();
	if(it->second.c.size()==1){
		m = max(m, maxBranch[1]);
		it++;
	}

	for( ; it != Nodes.end(); it++){
		node& n = it->second;
		if(n.c.size() > 1){
			set<int, greater<int> > weights;	
			for(size_t i=0; i<n.g.size(); i++){
				weights.insert(n.g[i] + maxBranch[n.c[i]->num]);			
			}
			set<int>::iterator sit = weights.begin();
			int r,l; r= *(sit++); l = *sit;
//			cout << "NOW : " << n.num << " , " << r << " + " << l <<endl;
			m = max(m, r+l);
//			m = max(m, *(sit++) + *sit);
		}
	}
		
	return m;
} 

int main(){
	cin >> N;
	Nodes[1] = node();
	
	int p,c,g;
	for(size_t i=1; i<N; i++){
		cin >> p >> c >> g;
		Nodes[c] = node(&(Nodes[p]), c, g);
	    (Nodes[p].c).push_back(&Nodes[c]);
	}	
	
//	print_tree();
	
	getMaxBranchWeight();	
	
//	for(size_t i=0; i<maxBranch.size(); i++)
//		cout << i<<" : " <<maxBranch[i] <<endl;
	cout << getLongestPath();

	return 0;
}
