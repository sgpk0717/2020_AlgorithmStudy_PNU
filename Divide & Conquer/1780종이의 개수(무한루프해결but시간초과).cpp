/*
	N x N 을 입력받는다.
	(Conquer)N x N 을 검사하면서 첫 번째 숫자와 끝까지 계속 같은지 비교한다.
	이때, 끝가지 계속 같으면 그 숫자의 카운트를 1 증가시킨다. 
	다르면 N/3 x N/3 으로 쪼개어(Divide) 9등분 한다.
	9등분한 각각의 행렬에 (Conquer)을 반복한다. 
*/
/*
	2020-01-20 무한루프 원인 찾음.
	작은 부분 3x3일때 devide를 하면 정수 나누기로 자동으로 내림이 되어
	제대로 나누지 못하는 오류가 있어 크기가 3x3은 따로 처리해 처리하였다.
	But, 시간초과. 
*/
#include <iostream>
#include <vector>
using namespace std;

struct Count {
	int negative_1;
	int zero;
	int one;
};

struct Count Cnt;

void Input(vector< vector<int> >& paper, int N) {
	int number;
	vector<int> line;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j) {
			cin >> number;
			line.push_back(number);
		}
		paper.push_back(line);
		line.clear();
	}
	Cnt.negative_1 = 0;
	Cnt.zero = 0;
	Cnt.one = 0;
}

void Divide(const vector< vector<int> >&, int, int, int, int, int);

void mini_conquer(const vector< vector<int> >& paper, int s1, int s2, int f1, int f2) {
	for(int i=s1; i<f1; ++i) {
		for(int j=s2; j<f2; ++j) {
			if(paper[i][j] == -1) ++Cnt.negative_1;
			else if(paper[i][j] == 0 ) ++Cnt.zero;
			else if(paper[i][j] == 1 ) ++Cnt.one;
		}
	}
}

void Conquer(const vector< vector<int> >& paper, int s1, int s2, int f1, int f2, int flag) {
	int p_number = paper[s1][s2];
	int i, j;
	for(i=s1; i<f1; ++i) {
		for(j=s2; j<f2 && (p_number == paper[i][j]); ++j)
			; // 비교하다가 끝까지 같으면 종료, 다르면 Divide.
		if(j<f2 && flag>3) {
			flag /= 3;
			Divide(paper, s1, s2, f1, f2, flag);
			return;
		}
		else if(j<f2 && flag<=3) {
			mini_conquer(paper, s1, s2, f1, f2);
			return;
		}
	} // 다 같으면 숫자 카운트 증가. 
	if(p_number == -1) ++Cnt.negative_1;
	else if(p_number == 0 ) ++Cnt.zero;
	else if(p_number == 1 ) ++Cnt.one;
	return;
}

void Divide(const vector< vector<int> >& paper, int s1, int s2, int f1, int f2, int flag) {
	Conquer(paper, s1, s2, f1/3, f2/3, flag);
	Conquer(paper, s1, f2/3, f1/3, f2/3+f2/3, flag);
	Conquer(paper, s1, f2/3+f2/3, f1/3, f2, flag);
	Conquer(paper, f1/3, s2, f1/3+f1/3, f2/3, flag);
	Conquer(paper, f1/3, f2/3, f1/3+f1/3, f2/3+f2/3, flag);
	Conquer(paper, f1/3, f2/3+f2/3, f1/3+f1/3, f2, flag);
	Conquer(paper, f1/3+f1/3, s2, f1, f2/3, flag);
	Conquer(paper, f1/3+f1/3, f2/3, f1, f2/3+f2/3, flag);
	Conquer(paper, f1/3+f1/3, f2/3+f2/3, f1, f2, flag);
	// 9등분. 
}

void Process(const vector< vector<int> >& paper, int N, int flag) {
	Conquer(paper, 0, 0, N, N, flag); // 0,0부터 N-1, N-1까지 탐색. 
}

void Output(void) {
	cout << Cnt.negative_1 << endl;
	cout << Cnt.zero << endl;
	cout << Cnt.one << endl;
}

int main(void) {
	vector< vector<int> > paper;
	int N, flag;
	cin >> N;
	flag = N;

	Input(paper, N);
	Process(paper, N, flag);
	Output();
	
	return 0;
}
