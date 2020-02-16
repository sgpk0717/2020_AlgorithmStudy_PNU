#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
	�� �ĵ��� �����°�ó�� �׷� ������ �ȴٰ� �����ߴµ� �����̾���.
	����1���� (1,3,6,5)�� (2,4,7)�� ������ �ȴٰ� �����ߴµ�
	�װͺ��� (1,3,7,5)�� (2,4,6)�� �� ȿ�����̱� �����̴�. 
*/

int town_N;
vector< int > population;
vector< vector<int> > relation;

void input() {
	cin >> town_N;
	population.push_back(0);			// index ���߱� 
	for(int i=0; i<town_N; i++) {		// �ֹ� �� 
		int population_tmp;
		cin >> population_tmp;
		population.push_back(population_tmp);
	}
	
	relation.resize(town_N+1);
	for(int i=1; i<town_N; i++) {		// ���� ���� ���� 
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
	// ó���� 0, ��������� 1, �Ϲ� ������ -1 
	vector< int > townlist(town_N+1, 0);
	stack < int > adjacent;
	
	adjacent.push(1);
	townlist[1] = 1;
	
	while( !adjacent.empty() ) {
		int target = adjacent.top();
		adjacent.pop();
		
		for(auto adj: relation[target]) {	// �̿����� Ž�� 
			int adj_adj_sum = 0; 
			if( townlist[adj] == 0 ) {		 // ���� ���� �ȵ��� ��� 
				adjacent.push(adj);
				if( townlist[target] == 1 ){ // target�� ������� 		
					townlist[adj] = -1;
				}
				else {	// target�� �Ϲ� �����̸� 
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
	// ó���� 0, ��������� 1, �Ϲ� ������ -1 
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
	int good_case = town1_is_good();	// 1�� ������ ��������� ���
	int normal_case = town1_is_normal();

//  cout << max(good_case, normal_case);

	return 0;
}

