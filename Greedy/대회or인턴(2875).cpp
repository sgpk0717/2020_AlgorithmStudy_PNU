#include <iostream>

using namespace std;

int Answer;

int main(void)
{
	int N, M, K;
	cin >> N >> M >> K;
	
	while(K!=0) {	
		if(N!=0 && N>=2*M) {
			N-=1;
		}
		else if(M!=0 && N<2*M) {
			M-=1;
		}
		--K;
	}
	
	if(N<2 || M==0) {
		cout << 0 << endl;
		return 0;
	}
	
	while(M!=0) {
		if(N>=2) {	
			++Answer;
			N-=2;
			M-=1;
		}
		else
			break;
	}
	
	cout << Answer << endl;
	
	
	
	return 0;
}
