// 백준 9237번 < 이장님 초대 > (트리 알고리즘 이용 안함) 
// 시간: 48ms		메모리: 2764KB 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N;
vector< int > TreeList;

void input() {
	cin >> N;
	for(int i=0; i<N; i++) {
		int tmp;
		cin >> tmp;
		TreeList.push_back(tmp);
	}
}

int grow_tree() {
	sort(TreeList.begin(), TreeList.end(), greater<int>() );  // 내림차순 정렬
	// 내림차순 정렬했을 때 (인덱스 + 나무길이)가 그 나무가 다 크는데 걸리는 시간 
	for(int index=0; index<N; index++) {
		TreeList[index] += index;
	} 
	
	return *max_element( TreeList.begin(), TreeList.end() );
}

int main(void) {
	input();
	int maxDate = grow_tree();
	
	// 제일 늦게 다 자란 나무 + 첫 나무 심는 날 + 이장님 초대하는 날  
	cout << maxDate + 2; 
	return 0;
}

