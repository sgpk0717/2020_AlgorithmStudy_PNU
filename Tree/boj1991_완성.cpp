// 백준 1991번 < 트리 순회 >
// 시간: 0ms	메모리: 1992kb 
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

map< char, Child > TREE;	// key: 부모노드, value: 자식노드 
stack< char > visit;
int node_N;

void input() {
	cin >> node_N;
	
	for(int i=0; i<node_N; i++) {
		char root_tmp, left_tmp, right_tmp;
		cin >> root_tmp >> left_tmp >> right_tmp;
		TREE[root_tmp] = { left_tmp, right_tmp };	// map에 부모를 key로,자식을 value로 넣는다 
	}
}

bool is_print( vector< char > &vec ,char target ) {
	for(auto s: vec) {
		if(s == target) return true;
	}
	return false;
}

void preorder() {	// 전위 순회: 루트-왼-오
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

void inorder() {	// 중위 순회: 왼-루트-오 
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
	
	preorder();		// 전위 순회: 루트-왼-오  
	inorder();		// 중위 순회: 왼-루트-오 
	postorder();	// 후위 순회: 왼-오-루트 

	return 0;
}

