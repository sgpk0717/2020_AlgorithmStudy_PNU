/* 1949 ��� ���� 
	2564KB	32ms	C++14 	1443B
	 
	Ʈ���� ��� ����Ŭ�� �����Ƿ� �� ó�� �Է¹޴� ��带 Root�� �Ͽ� 
	Ʈ���� preorder�� Ʈ���� ��ȸ�ϸ鼭 �� ��忡�� ��� ������ ���� �ƴ� ���� �α� �� ���� ���ϴ� 
	���� ��ȹ������ Ǯ���� 
	 
	�ð��� �ξ� ���� �ɸ� �ҽ����� ���淡 ���� ����� ã�ƺ���.
	 
	 https://www.acmicpc.net/problem/1949 


*/
#include <iostream>
#include <vector>

using namespace std;

int N;
	
struct node{
	static int count;
	int val,num;
	vector<node*> links;
	
	node(){	num = ++count;}
	node(int val){ 
		this->val = val;
	}
};
int node::count = 0;
node* Nodes;

int process(node& R, bool type, int from){
	int res = 0;
	int now = R.num;
	for(size_t i=0; i<R.links.size(); i++){
			if(R.links[i]->num == from) continue;
			
			if(!type)
				res += max(process(*R.links[i], !type, now), process(*R.links[i], type, now));
			else
				res += process(*R.links[i], !type, now);
		
	}
	if(type) res+=R.val;
//		cout << "Now Node Num is " << R.num << " , " << type <<endl; cout << "result : " << res <<endl;

	return res;
}

void printNodes(){
	for(size_t i=0; i<N; i++){
		cout << "NODE NUM : " << Nodes[i].num << " |  VALUE : " << Nodes[i].val <<endl;
		cout << "HAS LINKS TO {" ;	
		for(size_t j=0; j<Nodes[i].links.size(); j++)
			 cout << Nodes[i].links[j]->num << ", ";
		cout <<"}"<<endl;
	}
}

int main(void){
	int v,b,e;
	cin >> N;
	Nodes = new node[N];
	for(size_t i=0; i<N; i++){
		cin >> v;
		Nodes[i].val = v;	
	}
	for(size_t i=0; i<N-1; i++){
		cin >> b >> e;
		Nodes[b-1].links.push_back(&Nodes[e-1]);
		Nodes[e-1].links.push_back(&Nodes[b-1]);
	}		
//	printNodes();
	
	int Max = process(Nodes[0], true, Nodes[0].num);
//	cout << "----------------------------------------"<<endl;
	cout << max(Max, process(Nodes[0], false, Nodes[0].num));	
			
	return 0;
}
