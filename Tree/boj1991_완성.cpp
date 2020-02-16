// ���� 1991�� < Ʈ�� ��ȸ >
// �ð�: 0ms	�޸�: 1992kb 
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#define leftchild tree[target].left
#define rightchild tree[target].right
using namespace std;

struct Child {
	char left;
	char right;
};

map< char, Child > TREE;	// key: �θ���, value: �ڽĳ�� 
stack< char > visit;
int node_N;

void input() {
	cin >> node_N;
	
	for(int i=0; i<node_N; i++) {
		char root_tmp, left_tmp, right_tmp;
		cin >> root_tmp >> left_tmp >> right_tmp;
		TREE[root_tmp] = { left_tmp, right_tmp };	// map�� �θ� key��,�ڽ��� value�� �ִ´� 
	}
}

bool is_print( vector< char > &vec ,char target ) {
	for(auto s: vec) {
		if(s == target) return true;
	}
	return false;
}

void preorder() {	// ���� ��ȸ: ��Ʈ-��-��
	map< char, Child > tree = TREE;
	char target = 'A'; 
	
	cout << target;
	visit.push(target);
	
	while( 1 ) {
		if( leftchild != '.' ) {
			target = leftchild;
			cout << target;
			visit.push(target);
		} 
		else if( rightchild != '.' ) {
			target = rightchild;
			cout << target;
			visit.push(target);
		} 
		else {
			visit.pop();
			if( visit.empty() )	{ break; }
			char prev_target = target;
			target = visit.top();
			leftchild == prev_target ? leftchild = '.' : rightchild = '.';
		}
	}
	cout << "\n";
} 

void inorder() {	// ���� ��ȸ: ��-��Ʈ-�� 
	map< char, Child > tree = TREE;
	vector< char > printed;
	char target = 'A'; 
	
	visit.push(target);
	
	while( 1 ) {
		if( leftchild != '.' ) {
			target = leftchild;
			visit.push(target);
		} 
		else if( rightchild != '.' ) {
			cout << target;
			printed.push_back(target);
			target = rightchild;
			visit.push(target);
		} 
		else {
			visit.pop();
			if( !is_print(printed, target) ){	
				cout << target;
				printed.push_back(target);
			}
			if( visit.empty() )	{ break; }
			char prev_target = target;
			target = visit.top();
			leftchild == prev_target ? leftchild = '.' : rightchild = '.';
		}
	}
	cout << "\n";
}

void postorder() {
	map< char, Child > tree = TREE;
	char target = 'A'; 
	
	visit.push(target);
	
	while( 1 ) {
		if( leftchild != '.' ) {
			target = leftchild;
			visit.push(target);
		} 
		else if( rightchild != '.' ) {
			target = rightchild;
			visit.push(target);
		} 
		else {
			visit.pop();
			cout << target;
			if( visit.empty() )	{ break; }
			char prev_target = target;
			target = visit.top();
			leftchild == prev_target ? leftchild = '.' : rightchild = '.';
		}
	}
	cout << "\n";
}

int main(void) {
	input();
	
	preorder();		// ���� ��ȸ: ��Ʈ-��-��  
	inorder();		// ���� ��ȸ: ��-��Ʈ-�� 
	postorder();	// ���� ��ȸ: ��-��-��Ʈ 

	return 0;
}

