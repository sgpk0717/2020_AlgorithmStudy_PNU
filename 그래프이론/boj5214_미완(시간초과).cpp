#include <iostream>
#include <vector>
using namespace std;

typedef vector< int > vec_i;

/*
 * �ð��ʰ� �ذ���
 * cin�� scanf��  
 * �̿����� ������������ �湮 
 *   ( ���� ū ������ ������ Ž���ϰ� ���������� ������ ���� ������ ���� Ž������ )
 * �̶������� �ּ� ������� count�� Ŀ���� Ž�� ����	 
*/

vector< vec_i > List;
int N, K, M;	// ���� ��, Ʃ�� �� �� ����, Ʃ�� ����
int result;

void print_list() {
	cout << "----------print_list------------\n";
	for(int i=0; i<N+1; i++) {
		cout << i << ":  ";
		for(auto s: List[i]) {
			cout << s << ' ';
		}
		cout << "\n";
	}
}

void print_visit( vec_i &visit ) {
	cout << "----------visited------------\n";
	for(auto st: visit) { cout << st << " -> "; }
	cout << N << "\n";
}

bool exist( int index, int data ) {
	for( auto s: List[index] ) {
		if( s == data )	{ return true; } 
	}
	return false;
}

void input() { 
	scanf("%d%d%d", &N, &K, &M);
	List.resize( N+1 );
	
	for(int i = 0; i < M; i++) {
		int* hypertube = new int[ K ];
		for(int j = 0; j < K; j++) { scanf("%d", &hypertube[j]); }
		for(int ii=0; ii<K; ii++) {		// hypertube �� Ÿ�� 
			int station_i = hypertube[ii];
			for(int jj=0; jj<K; jj++) {	// hypertube �� Ž�� 
				int station_j = hypertube[jj];
				if( !exist( station_i, station_j ) ) {
					List[ station_i ].push_back( station_j );
				}
			}
		}
		delete[] hypertube;
	}	
}

bool has_visit( int station, vec_i &visit ) {
	for( auto stn: visit ) {
		if( stn == station ) { return true; }
	}
	return false;
}

void move( int start_stn, vec_i visit, int count_stn ) {
	visit.push_back( start_stn );
	count_stn++;
	if( count_stn >= result )
		return ;
	
	vec_i:: iterator iter = List[start_stn].end();
	iter--;	
	
	for( ; iter >= List[start_stn].begin() ; iter-- ) {
		if( *iter == N ) {		 
			//print_visit( visit );	
			count_stn++;
			result = ( count_stn < result ) ? count_stn : result ;
			
			return ;			// ���������� ���� ������ �˻���� 
		}
		else if( !has_visit( *iter, visit ) ) {
			move( *iter, visit, count_stn );
		}
	}
}

int main(void) {
	input();
	//print_list();
	
	if( N == 1 ) {
		cout << 1 ;
		return 0;
	} 
	
	vec_i visit;
	result = N + 1 ;
	move( 1, visit, 0 );
	
	cout << ( result == N+1 ? -1 : result );
	return 0;
}
