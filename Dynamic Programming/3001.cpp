#include <bits/stdc++.h>

using namespace std;

bool isSatisfyS(long long num, long long sum)
{
	int s=0;
	
//	cout << num << " => ";
	while(num!=0) {
//		cout << num%10 << ' ';
		s += num%10;
		if(s>sum)	return false;
		num = num/10;
	}
	if(s==sum) 	return true;
	else		return false;
}
int main(void)
{
	ifstream ifs("3001_2.inp");
	long long A=-1, B=-1, S=-1; // 1<=A<=B<10^5, 1<=S<=135
		
	ifs >> A >> B >> S;
	ifs.close();
	
//	cin >> A >> B >> S;

	vector<long long> answer;

	for(long long i=A; i<=B; ++i) {
		if(isSatisfyS(i,S)) {
			cout << i << " => Satisfied!!!\n";
			answer.push_back(i);
		}
//		cout << "\n";
	}
	
	cout << answer.size() << endl;
	if(!answer.empty())	 cout << answer[0] << endl;
	
    return 0;
}
