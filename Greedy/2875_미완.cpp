/*
여학생의 수가 남학생의 수보다 2배 더 많은지 검사
많다면 K의 수를 여학생 수에서 감소시킴
여학생의 수에서 K의 남은 수가 부족하다면 남학생 수에서 감소시킴
남학생의 수에서도 부족하다면 팀의 수를 감소시킨 뒤 다시 K 감소시키기 
*/

#include <bits/stdc++.h>

using namespace std;

int calNumTeam(int n, int m, int k, int team)
{
	int cnt=3; 
	while(k>0) {
		--team;
		while(cnt!=0) {
			if(n>0) {
			--n; --k;
			--cnt;
				if(n>0) {
					--n; --k;
					--cnt;
				}
				
			} else if(m>0) {
				
			} else {
				
			}	
		}
		
		cnt	= 3;
	}
	
	return team;
}

int main(void)
{
	int N, M, K; // 0<=M<=100, 0<=N<=100, 0<=K<=M+N
	ifstream ifs("2875_1.inp");
	ifs >> N >> M >> K;
	ifs.close();
	
	int k = K; 
	int numTeam = 0;
	
	if(N>2*M) {
		numTeam = M;
		k = k-(N-2*M);
		if(k>0) {
			numTeam = calNumTeam(N,M,k,numTeam);
		}
	} else {
		numTeam = calNumTeam(N,M,k,numTeam);
	}
	
	cout << numTeam;
	
	return 0;
}
