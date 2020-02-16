#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
	원 파동이 퍼지는것처럼 그룹 지으면 된다고 생각했는데 착각이었다.
	예제1에서 (1,3,6,5)와 (2,4,7)로 나누면 된다고 생각했는데
	그것보다 (1,3,7,5)와 (2,4,6)이 더 효율적이기 때문이다. 
*/

int town_N;
vector< int > population;
vector< vector<int> > relation;

void input() {
	cin >> town_N;
	population.push_back(0);			// index 맞추기 
	for(int i=0; i<town_N; i++) {		// 주민 수 
		int population_tmp;
		cin >> population_tmp;
		population.push_back(population_tmp);
	}
	
	relation.resize(town_N+1);
	for(int i=1; i<town_N; i++) {		// 마을 사이 관계 
		int town1, town2;
		cin >> town1 >> town2;
		relation[town1].push_back(town2);
		relation[town2].push_back(town1);
	}
}

void print_relation() {
	cout << "------------relation--------------\n";
	for(int i=0; i<town_N+1; i++) {
		cout << i << ": ";
		for(auto s: relation[i]) {
			cout << s << ' ';
		} 
		cout << "\n";
	}
	cout << "-----------relation END------------\n";
}

int town1_is_good() {
	int people = 0;
	// 처음엔 0, 우수마을은 1, 일반 마을은 -1 
	vector< int > townlist(town_N+1, 0);
	stack < int > adjacent;
	
	adjacent.push(1);
	townlist[1] = 1;
	
	while( !adjacent.empty() ) {
		int target = adjacent.top();
		adjacent.pop();
		
		for(auto adj: relation[target]) {	// 이웃마을 탐색 
			int adj_adj_sum = 0; 
			if( townlist[adj] == 0 ) {		 // 아직 지정 안됐을 경우 
				adjacent.push(adj);
				if( townlist[target] == 1 ){ // target이 우수마을 		
					townlist[adj] = -1;
				}
				else {	// target이 일반 마을이면 
					for(auto adj_adj: relation[adj]) {
						if( townlist[adjadj] == 0 ) {
							adj_adj_sum += population[adjadj];
						}
					} 
					townlist[adj] = 
						population[adj] >= adj_adj_sum ? 1 : -1;
					
				}
				
			}
			
			
		
		}
	}
	
	for(int i=1; i<=town_N; i++) {
		if( townlist[i] == 1 ) { people += population[i]; }
	}
	
	cout << "townlist_1 is excellent\n";
	for(auto s: townlist) { cout << s << ' '; }
	
	cout << "\npeople_1: " << people << endl;
	
	return people;
}

int town1_is_normal() {
	int people = 0;
	// 처음엔 0, 우수마을은 1, 일반 마을은 -1 
	vector< int > townlist(town_N+1, 0);
	stack < int > adjacent;
	
	adjacent.push(1);
	townlist[1] = -1;
	
	while( !adjacent.empty() ) {
		int target = adjacent.top();
		adjacent.pop();
		
		for(auto adj: relation[target]) {
			int adj_sum = 0; 
			if( townlist[adj] == 0 ) {
				if( townlist[target] == 1 ){
					adjacent.push(adj);		
					townlist[adj] = -1;
				}
				else {	// if (townlist[target] == -1)
						
				}
				
			}
			
			
		
		}
	}
	
	for(int i=1; i<=town_N; i++) {
		if( townlist[i] == 1 ) { people += population[i]; }
	}
	
	cout << "townlist_1 is normal\n";
	for(auto s: townlist) { cout << s << ' '; }
	
	cout << "\npeople_2: " << people << endl;
	
	return people;
}

int main(void) {
	input();
	print_relation(); 
	int good_case = town1_is_good();	// 1번 마을이 우수마을인 경우
	int normal_case = town1_is_normal();

//  cout << max(good_case, normal_case);

	return 0;
}

