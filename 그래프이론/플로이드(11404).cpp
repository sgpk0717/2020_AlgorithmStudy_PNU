#include <iostream>
#include <vector>
#define INF 999999

using namespace std;

int N, M;

vector< vector<int> > inputs;

void print_input(void) {
	for(int i=1;i<inputs.size();++i) {
		for(int j=1;j<inputs[i].size();++j)
			cout << inputs[i][j] << ' ';
		cout << endl;
	}
}
		

int main(void)
{
	cin >> N >> M;
	int source, destination, cost;
	inputs.resize(N+1, vector<int>(N+1,INF));
	
	for(int i=0;i<M;++i) {
		cin >> source >> destination >> cost;
		inputs[source][destination]=min(inputs[source][destination],cost);
	}
	
	//print_input();
	
	for(int i=1;i<=N;++i) {
		for(int j=1;j<inputs.size();++j) {
			for(int k=1;k<inputs[j].size();++k) {
				if(inputs[j][i]!=INF && inputs[i][k]!=INF)
					inputs[j][k] = min(inputs[j][k],inputs[j][i]+inputs[i][k]);			
			}
		}
		
		//print_input();
	}
	for(int i=1;i<=N;++i)
		inputs[i][i]=0;
	
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(inputs[i][j]==INF)
				inputs[i][j]=0;
	
	print_input();
		
	
	return 0;
}
