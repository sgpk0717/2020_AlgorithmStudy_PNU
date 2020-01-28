/*
	N x N �� �Է¹޴´�.
	(Conquer)N x N �� �˻��ϸ鼭 ù ��° ���ڿ� ������ ��� ������ ���Ѵ�.
	�̶�, ������ ��� ������ �� ������ ī��Ʈ�� 1 ������Ų��. 
	�ٸ��� N/3 x N/3 ���� �ɰ���(Divide) 9��� �Ѵ�.
	9����� ������ ��Ŀ� (Conquer)�� �ݺ��Ѵ�. 
*/
/*
	2020-01-20 ���ѷ��� ���� ã��.
	���� �κ� 3x3�϶� devide�� �ϸ� ���� ������� �ڵ����� ������ �Ǿ�
	����� ������ ���ϴ� ������ �־� ũ�Ⱑ 3x3�� ���� ó���� ó���Ͽ���.
	But, �ð��ʰ�. 
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
			; // ���ϴٰ� ������ ������ ����, �ٸ��� Divide.
		if(j<f2 && flag>3) {
			flag /= 3;
			Divide(paper, s1, s2, f1, f2, flag);
			return;
		}
		else if(j<f2 && flag<=3) {
			mini_conquer(paper, s1, s2, f1, f2);
			return;
		}
	} // �� ������ ���� ī��Ʈ ����. 
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
	// 9���. 
}

void Process(const vector< vector<int> >& paper, int N, int flag) {
	Conquer(paper, 0, 0, N, N, flag); // 0,0���� N-1, N-1���� Ž��. 
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
