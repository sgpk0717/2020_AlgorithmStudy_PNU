#include <bits/stdc++.h>

using namespace std;

void print(vector<int> vec)
{
	for(int i=0; i<vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
	cout << endl;
//	cout << "=> " << vec.size() << endl;
}
int main(void)
{
//	ifstream ifs("6359_1.inp");
	vector<int> nVec; // 5<=n<=100
	int T=-1; // case 개수 
	
//	ifs >> T;
	cin >> T;
	int n=-1;
	for(int i=0; i<T; ++i) {
		cin >> n;
		nVec.push_back(n);
	}	
//	ifs.close();
	
	vector<int> answer;
	for(int i=0; i<T; ++i) {
//		cout << i << "th case" << endl;
		vector<int> jail(nVec[i],1); // -1=>잠김, 1=>열림
		for(int k=2; k<=nVec[i]; ++k) {
			for(int j=0; j<nVec[i]; ++j) {
				if((j+1)%k==0) {
					jail[j]*=-1;
				}
			}
//			print(jail);
		}
		n = count(jail.begin(), jail.end(), 1);
		answer.push_back(n);
	}
	
	for(int i=0; i<T; ++i)
		cout << answer[i] << endl;
	
    return 0;
}
