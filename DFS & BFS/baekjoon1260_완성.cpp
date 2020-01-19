/* ����1260��   �ð�: 24ms */
#include <iostream>
#include <array>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#define MAX_V 1001
using namespace std;

array< list<int>, MAX_V > maplist;
int vertex_N, edge_N, startpoint;
bool is_exist(); 
void setData();
void DFS();
void BFS();

int main(void) {
	cin >> vertex_N >> edge_N >> startpoint;
	
	setData();	// ������� ���·� ���� 

	DFS();
	BFS();
	
	return 0;
}

bool is_exist_in_list( int start, int end ) {	 
	for( auto s: maplist[start] ) {
		if( s == end )	{ return true; }
	}
	return false;
}

bool is_visit( vector<int> visit, int vertex ) {
	for(auto v: visit) {
		if( v == vertex ) {	return true; }
	}
	return false;
}

void setData() {
	int start, end;
	for(int i=0; i<edge_N; i++) {
		cin >> start >> end;
		if( !is_exist_in_list( start, end ) ) {	
			maplist[start].push_back(end);		// �Է¹��� edge �߰�
		}
		if( !is_exist_in_list( end, start ) ) {
			maplist[end].push_back(start);		// edge�� �պ����� ��� 
		}
	}
	// for(auto s: maplist)	{ s.sort(); }	// �� ���� �ȵǴ��� �𸣰���
	for(int i=0; i<maplist.size(); i++) {	maplist[i].sort(); }	// list �������� ����(�켱���� ���) 
}

void DFS() {
	stack < int > stack;
	vector< int > visit;
	
	stack.push(startpoint);				// ���� ���� ���� 
	visit.push_back(startpoint);

	while( !stack.empty() ) {
		int target = stack.top();		// Ÿ��(��� ����)�� stack�� top���� 
		list< int > sublist = maplist[target];	// Ÿ�� ������ ����� ����list 
		list< int >:: iterator iter;
		
		for(iter = sublist.begin(); iter != sublist.end(); iter++) {	
			if( !is_visit( visit, *iter ) ) {	// ���ư� ���� ������ 
				target = *iter;					// ���ư��� Ÿ�� ���� 
				stack.push(target);
				visit.push_back(target);
				break;
			}
		}
		if( iter == sublist.end() ) {	// ���ư� ���� ������ 
			stack.pop();				// stack���� ���� 
		}
	}
	
//	cout << "DFS: ";
	for(auto v: visit) { cout << v << ' '; }
	cout << "\n";
}

void BFS() {
	queue < int > queue; 
	vector< int > visit;
	
	queue.push( startpoint );
	visit.push_back( startpoint );
	
	while( !queue.empty() ) {
		int target = queue.front();
		list< int > sublist = maplist[target];
		list< int >:: iterator iter;
		
		for(iter = sublist.begin(); iter != sublist.end(); iter++) {
			if( !is_visit( visit, *iter ) ) {
				queue.push( *iter );
				visit.push_back( *iter );
			}
		}
		if( iter == sublist.end() ) {
			queue.pop();
		}
	}
//	cout << "BFS: ";
	for(auto v: visit) { cout << v << ' '; }
	cout << "\n";	
}
