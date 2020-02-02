#include <bits/stdc++.h>

using namespace std;

void print(vector< vector<string> > vec)
{
	for(int i=0; i<vec.size(); ++i) {
		for(int j=0; j<vec[i].size(); ++j) {
			cout << vec[i][j] << "  -";
		}
		cout << endl;
	}
}

int main(void)
{
//	ifstream ifs("9251_1.inp");
	string s1="", s2="";
	
//	ifs >> s1 >> s2;
//	ifs.close();
	
	cin >> s1 >> s2;
	
//	cout << s1 << ' ' << s2 << endl;
	
	vector< vector<string> > answer;
	
	for(int i=0; i<s1.size()+1; ++i) {
		vector<string> tmp(s2.size()+1, "");
		answer.push_back(tmp);
	}
//	print(answer);
	
	for(int i=1; i<s1.size()+1; ++i) {
		for(int j=1; j<s2.size()+1; ++j) {
			if(s1[i-1]==s2[j-1]) {
				string diag = answer[i-1][j-1];
				answer[i][j] += (diag+s1[i-1]);
			} else {
				string left = answer[i-1][j];
				string up = answer[i][j-1];
				if(left.size()>=up.size()) {
					answer[i][j] += left;
				} else {
					answer[i][j] += up;
				}
			}
		}
	}
	
//	print(answer);
	
	cout << answer[s1.size()][s2.size()].size();
	
    return 0;
}
