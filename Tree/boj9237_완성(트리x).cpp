// ���� 9237�� < ����� �ʴ� > (Ʈ�� �˰��� �̿� ����) 
// �ð�: 48ms		�޸�: 2764KB 
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
	sort(TreeList.begin(), TreeList.end(), greater<int>() );  // �������� ����
	// �������� �������� �� (�ε��� + ��������)�� �� ������ �� ũ�µ� �ɸ��� �ð� 
	for(int index=0; index<N; index++) {
		TreeList[index] += index;
	} 
	
	return *max_element( TreeList.begin(), TreeList.end() );
}

int main(void) {
	input();
	int maxDate = grow_tree();
	
	// ���� �ʰ� �� �ڶ� ���� + ù ���� �ɴ� �� + ����� �ʴ��ϴ� ��  
	cout << maxDate + 2; 
	return 0;
}

