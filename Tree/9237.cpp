#include <bits/stdc++.h>

using namespace std;

bool checkAllZero(vector<int> vec)
{
	for(int i=0; i<vec.size(); ++i) {
		if(vec[i]!=0) return false;
	}
	return true;
}
void print(vector<int> vec)
{
	for(int i=0; i<vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
	cout << endl;
}
bool desc(int a, int b)
{
	return a>b;
}
int main(void)
{
//	ifstream ifs("9237_2.inp");
	int N = 0; // 묘목의 수 1<=N<=100000
	int t = 0; // 묘목이 자라는데 걸리는 일수 1<=t<=1000000
	int day = 2;
	
	vector<int> tree;
	
//	ifs >> N;
	cin >> N;
	for(int i=0; i<N; ++i) {
//		ifs >> t;
		cin >> t;
		tree.push_back(t);
	}
	
//	ifs.close();
	
	sort(tree.begin(), tree.end(), desc);
	
	vector<int> growing;
	int plantTree = 0;
	growing.push_back(tree[plantTree]);
	++day; ++plantTree;
	
	while(!checkAllZero(growing)) {
		++day;
		if(plantTree!=N) {
			growing.push_back(tree[plantTree]);
			++plantTree;		
		}
		for(int i=0; i<growing.size(); ++i) {
			if(growing[i]!=0) --growing[i];
		}		
		
//		cout << "Day " << day << " : ";
//		print(growing);
	}
	
//	cout << "\nDay : " << day << endl;
	cout << day;
    return 0;
}
