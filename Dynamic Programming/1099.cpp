/* 1099 �� �� ���� ���� 
	1988KB	0ms	C++14 	1822B
	
	 �� ������� ���� �� �𸣰ڴ� �޸𸮸� 1000KB �̸����� ���� �����ڰ� ������ 
    �ܾ ������ string ���͸� ���� �ξ��� ������ ���ϴ�. 
	 ����� C ��Ÿ�Ϸ� ���� �ʰ� string �� cin,cout �� ��µ��� �ð��� 0ms�� ����. 
	
*/
 
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef string s;

s S;	 					// ���� 
vector<s> Words(50);  		// ���� �ܾ��� ���� 
vector<s> Sorteds(50); 		// ���ĺ� �������� ���ĵ� �ܾ��� ���� 
vector<int> Costs(50, -1); 	// �ܾ� �� ��� 
int N;						// �ܾ� ����  

int getDiff(s A, int beg){ 	// ������ beg��ġ���Ϳ� �ܾ� A ���� ���ĺ� ���� ��
	int diff=0;
	for(int i=0; i<A.size(); i++){
		if(S[beg+i]!=A[i]) diff++;
	} 
	return diff;
}

int CheckWords(int pos){
	if(Costs[pos]!=-1) return Costs[pos];
	
	int Min = S.size()+1;
	
	for(size_t i=0; i<N; i++){  // �ܾ� �迭�� ����. 
		int nextpos = pos + Sorteds[i].size();
		if(nextpos < S.size()) {	
			 s Piece = S.substr(pos, Sorteds[i].size());  						// �ܾ��� ũ�� ��ŭ �� ��ġ ���� ������ �ڸ��ϴ� 
			sort(Piece.begin(), Piece.end());
			if(!Piece.compare(Sorteds[i])){   									// �ڸ� ���� ������ �ܾ ������ �� ���� ���� �� �� 
					int cost = getDiff(Words[i], pos);  
					Min = min(Min , cost + CheckWords(pos+Sorteds[i].size() )); // ������ ��� + ������ �̾ ������� ���� ��ȯ�� 
			} 
		}
		else if(nextpos == S.size()){
			s Piece = S.substr(pos, Sorteds[i].size()); 	 // �ܾ��� ũ�� ��ŭ �� ��ġ ���� ������ �ڸ��ϴ� 
			sort(Piece.begin(), Piece.end());
			if(!Piece.compare(Sorteds[i])){ 			 	 // �ڸ� ���� ������ �ܾ ������ �� ���� ���� �� ��
					int cost = getDiff(Words[i], pos);  
					Min = min(Min , cost); 				   	 // ������ ��븸 ó��  
			} 
		}
	}

	Costs[pos] = Min;
	return Costs[pos];
}

int main(){
	cin >> S >> N;
	s inp;
	for(size_t i=0; i<N; i++){
		cin >> inp;
		Words[i] = inp;
		sort(inp.begin(), inp.end());
		Sorteds[i]=inp;
	}
	
	int answer = CheckWords(0);	
	if(answer > S.size()) cout << -1;
	else cout << answer;
	return 0;
} 
