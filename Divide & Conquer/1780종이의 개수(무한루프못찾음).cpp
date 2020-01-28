/*
	N x N �� �Է¹޴´�.
	(Conquer)N x N �� �˻��ϸ鼭 ù ��° ���ڿ� ������ ��� ������ ���Ѵ�.
	�̶�, ������ ��� ������ �� ������ ī��Ʈ�� 1 ������Ų��. 
	�ٸ��� N/3 x N/3 ���� �ɰ���(Divide) 9��� �Ѵ�.
	9����� ������ ��Ŀ� (Conquer)�� �ݺ��Ѵ�. 
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

void Divide(const vector< vector<int> >&, int, int, int, int);

void Conquer(const vector< vector<int> >& paper, int s1, int s2, int f1, int f2) {
	int p_number = paper[s1][s2];
	int i, j;
	for(i=s1; i<f1; ++i) {
		for(j=s2; j<f2 && (p_number == paper[i][j]); ++j)
			; // ���ϴٰ� ������ ������ ����, �ٸ��� Divide.
		if(j<f2) {
			Divide(paper, s1, s2, f1, f2);
			break;
		}
	} // �� ������ ���� ī��Ʈ ����. 
	if(p_number == -1) ++Cnt.negative_1;
	else if(p_number == 0 ) ++Cnt.zero;
	else if(p_number == 1 ) ++Cnt.one;
	return;
}

void Divide(const vector< vector<int> >& paper, int s1, int s2, int f1, int f2) {
	Conquer(paper, s1, s2, f1/3, f2/3);
	Conquer(paper, s1, f2/3, f1/3, f2/3+f2/3);
	Conquer(paper, s1, f2/3+f2/3, f1/3, f2);
	Conquer(paper, f1/3, s2, f1/3+f1/3, f2/3);
	Conquer(paper, f1/3, f2/3, f1/3+f1/3, f2/3+f2/3);
	Conquer(paper, f1/3, f2/3+f2/3, f1/3+f1/3, f2);
	Conquer(paper, f1/3+f1/3, s2, f1, f2/3);
	Conquer(paper, f1/3+f1/3, f2/3, f1, f2/3+f2/3);
	Conquer(paper, f1/3+f1/3, f2/3+f2/3, f1, f2);
	// 9���. 
}

void Process(const vector< vector<int> >& paper, int N) {
	Conquer(paper, 0, 0, N, N); // 0,0���� N-1, N-1���� Ž��. 
}

void Output(void) {
	cout << Cnt.negative_1 << endl;
	cout << Cnt.zero << endl;
	cout << Cnt.one << endl;
}

int main(void) {
	vector< vector<int> > paper;
	int N;
	cin >> N;

	Input(paper, N);
	Process(paper, N);
	Output();
	
	//
	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j)
			cout << paper[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
