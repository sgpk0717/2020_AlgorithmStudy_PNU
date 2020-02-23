// 36ms

#include <iostream>
#include <vector>

using namespace std;

int N, K;

vector<int> value;

int processing(void) {
	int remain=K;
	int cnt=0;	
	while(remain!=0) {
		for(int i=0;i<N;++i) {
			if(value[i]<=remain) {
				while(value[i]<=remain) {
					remain-=value[i];
					++cnt;
				}
			}
		}
	}
	return cnt;
}

int main(void)
{
	cin >> N >> K;
	
	value.resize(N);
	
	for(int i=N-1;i>=0;--i)
		cin >> value[i];
	
	cout << processing() << endl;
	
	return 0;
}
