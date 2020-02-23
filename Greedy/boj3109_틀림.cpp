#include <iostream>
#include <vector>
using namespace std;

#define right_go 	 !( Map[x][y+1] != 0 )
#define up_diag_go 	 !( x==0 || Map[x-1][y+1] != 0 ) && !( Map[x][y+1] > 1 && Map[x-1][y] > 1 )
#define down_diag_go !( x>=Row-1 || Map[x+1][y+1] != 0 ) && !( Map[x][y+1] > 1 && Map[x+1][y] > 1 )

int Row, Col;
vector< vector< int > > Map;

void input() {
	cin >> Row >> Col;
	Map.resize( Row );
	
	char tmp;
	for(int i=0; i<Row; i++) {
		for(int j=0; j<Col; j++) {
			cin >> tmp;
			if( tmp == '.' ) { Map[i].push_back( 0 ); }
			else if( tmp == 'x' ) { Map[i].push_back( 1 ); }
			else { }
		}
	}
}

void print_map() {
	for(auto i: Map) {
		for(auto j: i) { cout << j << ' '; }
		cout << "\n";
	}
}

int install() {
	int cnt = 0;
	int x, y;
	for(int start_x=0; start_x<Row; start_x++) {
		vector< pair< int, int > > path;
		x = start_x;
		y = 0;
		
		while( y != Col-1 ) {
			if( up_diag_go ) {
				x -= 1;  y += 1;  
				path.push_back( make_pair(x,y) );
				cout << "up_diag" << endl; 
			}
			else if( right_go ) {
				y += 1;  
				path.push_back( make_pair(x,y) );
				cout << "right" << endl; 
			}
			else if( down_diag_go ) { 
				x += 1;  y += 1;
				path.push_back( make_pair(x,y) );
				cout << "down_diag" << endl;
			}
			else { 
				cout << "stop\n" << endl;  
				break; 
			}
		}
		if( y == Col - 1 ) {
			for(auto walk: path) {
				Map[walk.first][walk.second] = start_x + 2;
			}
			cnt++;
			cout << "success\n";
			print_map();
		}
	}
	return cnt;
}

int main(void) {
	input();
	print_map();
	
	cout << install();

	return 0;
}

