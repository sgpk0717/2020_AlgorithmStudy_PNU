#include <iostream>
#include <fstream>
#include <vector> 

using namespace std;

vector< vector<char> > inputs;

void preorder(const vector<char>& node) {
	cout << node[0];
	if(node[1]!='.') 
		preorder(inputs[node[1]-'A']);	
	if(node[2]!='.') 
		preorder(inputs[node[2]-'A']);
	
}

void inorder(const vector<char>& node) {
	if(node[1]!='.') 
		inorder(inputs[node[1]-'A']);	
	cout << node[0];
	if(node[2]!='.') 
		inorder(inputs[node[2]-'A']);
}

void postorder(const vector<char>& node) {
	if(node[1]!='.') 
		postorder(inputs[node[1]-'A']);	
	if(node[2]!='.') 
		postorder(inputs[node[2]-'A']);
	cout << node[0];
}

int main(void)
{
	ifstream ifs("1991_1.txt");
	int N;
	char n1, n2, n3;
	
	cin >> N;
//	ifs >> N;
	
	inputs.resize(N, vector<char>(3));
	for(int i=0;i<N;++i) {
		cin >> n1 >> n2 >> n3;
//		ifs >> n1 >> n2 >> n3;
		inputs[n1-'A'][0] = n1;
		inputs[n1-'A'][1] = n2;
		inputs[n1-'A'][2] = n3;
	}
	
	preorder(inputs[0]);
	cout << endl;
	inorder(inputs[0]);
	cout << endl;
	postorder(inputs[0]);
	cout << endl;
	
	return 0;
}
