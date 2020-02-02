#include <iostream>
#include <fstream>

using namespace std;

int tile[1001];

void cal_tile_num(void) {
	tile[0]=0;
	tile[1]=1;
	tile[2]=2;
	
	for(int i=3;i<=1000;++i) {
		tile[i] = tile[i-1] + tile[i-2];
		tile[i]%=10007;
	}
		
}

int get_tile_num(int n) {
	return tile[n];	
}

int main(void)
{
	int n;
	
	cin >> n;
	
	cal_tile_num();
	cout << get_tile_num(n) << endl;
	
	
	return 0;
}
