#include <iostream>
#include <vector>
using namespace std;

typedef vector< int > vec_i;

/*
 * 시간초과 해결노력
 * cin을 scanf로  
 * 이웃역을 내림차순으로 방문 
 *   ( 가장 큰 숫자의 역부터 탐색하고 마지막역이 나오면 같은 레벨의 역은 탐색안함 )
 * 이때까지의 최소 결과보다 count가 커지면 탐색 멈춤	 
*/

vector< vec_i > List;
int N, K, M;	// 역의 수, 튜브 당 역 개수, 튜브 개수
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
		for(int ii=0; ii<K; ii++) {		// hypertube 내 타겟 
			int station_i = hypertube[ii];
			for(int jj=0; jj<K; jj++) {	// hypertube 내 탐색 
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
			
			return ;			// 마지막역과 같은 레벨은 검사안함 
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
