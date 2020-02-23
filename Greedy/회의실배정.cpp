#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Answer;
vector< vector<int> > reservation;

bool compare(const vector<int>& v1, const vector<int>& v2) {
	if(v1[1] == v2[1])
		return v1[0] < v2[0];
	return v1[1] < v2[1];	
}

int main(void)
{
	cin >> N;
	reservation.resize(N, vector<int>(2,0));
	int s, e;
	
	for(int i=0;i<N;++i) {
		cin >> s >> e;
		reservation[i][0] = s;	
		reservation[i][1] = e;
	}
	
	sort(reservation.begin(),reservation.end(),compare);
	
//	for(int i=0;i<N;++i)
//		cout << reservation[i][0] << ' ' << reservation[i][1] << endl;
		
	s = reservation[0][0];
	e = reservation[0][1];
	++Answer;
	for(int i=1;i<N;++i) {	
		if(reservation[i][0]>=e) {
			s = reservation[i][0];
			e = reservation[i][1];
			++Answer;
		}
	}
	
	cout << Answer << endl;
	
	return 0;
}
