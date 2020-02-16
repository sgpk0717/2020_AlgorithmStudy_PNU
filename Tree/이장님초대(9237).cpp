#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool flag;
int end_value;
int Answer;
vector<int> trees;


void print_trees(void) {
	for(int i=0;i<N;++i)
		cout << trees[i] << ' ';
	cout << endl;
}

void processing(void) {
	for(int i=0;i<N;++i) {
		Answer = trees[i]+i+2 > Answer ? trees[i]+i+2 : Answer;
	}
}

int main(void)
{
	cin >> N;
	trees.resize(N);
	
	for(int i=0;i<N;++i)
		cin >> trees[i];
		
	sort(trees.begin(), trees.end(),greater<int>());
//	print_trees();
	
	processing();
	
	cout << Answer << endl;
	
	return 0;
}
