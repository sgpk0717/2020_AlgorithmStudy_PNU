/*

*/

#include <bits/stdc++.h>

using namespace std;

void print(vector<int> vec)
{
	for(int i=0; i<vec.size(); ++i) 
		cout << vec[i] << ' ';
	cout << endl;
}

int main(void)
{
	int N, K; // 1<=N<=10, 1<=K<=100000000
//	ifstream ifs("11047_2.inp");
//	ifs >> N >> K;
	cin >> N >> K;
	
	vector<int> coinList;
	for(int i=0; i<N; ++i) {
		int coin;
//		ifs >> coin;
		cin >> coin;
		coinList.push_back(coin);
	}
//	ifs.close();
	
//	cout << "동전 종류" << endl;
//	print(coinList);
//	cout << "-------------------------------" << endl;
	
	int numCoin = 0;
	
	for(int i=coinList.size()-1; i>=0; --i) {
		int coinTmp = coinList[i];
		
		while(1) {
			if(K-coinTmp<0)		break;
			numCoin++;
			K = K-coinTmp;
			
//			cout << coinTmp << endl;
		}
		
		if(K==0) break;
	}
	
	cout << numCoin;
	
	return 0;
}
