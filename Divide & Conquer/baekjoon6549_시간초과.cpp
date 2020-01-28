// ���� 6549 < ������׷����� ���� ū ���簢�� > 
// ���簢�� ����: 1~100,000		����: 0 ~ 1,000,000,000 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector < ll > histogram, area, result;
int printcnt = 1;

void solve( int rect_cnt ) {
	//for(auto s: histogram) { cout << s << ' '; }  cout << "\n\n";
	int maxArea = 0;
	vector < ll > :: iterator target_it, it, r_it;
	
	for(target_it = histogram.begin(); target_it != histogram.end(); target_it++) {
		int connected = 1;		// ���ӵ� ���簢�� ����. target�����̹Ƿ� 1���ͽ��� 
		it = r_it = target_it;
		//cout << "\ntarget: " << *target_it << endl;
		
		while( it != histogram.end()-1 ) {
		//	cout << "it: " << *it << endl;
			it++;
			if( *it == 0 || *it < *target_it )	{ break; }
			connected++;
		}
		
		while( r_it > histogram.begin() ) {
		//	cout << "r_it: " << *r_it << endl;
			r_it--;
			if( *r_it == 0 || *r_it < *target_it )	{ break; }
			connected++;
		}
		
		/*
		while( it != histogram.end()-1 || r_it > histogram.begin() ) {
			if( it != histogram.end()-1 ) {
				//cout << "it: " << *it << endl;
				it++;
				if( *it == 0 || *it < *target_it )	{ it = histogram.end()-1; }
				else { connected++; }
			}
			if( r_it > histogram.begin() ) {
				//cout << "rit: " << *r_it << endl;
				r_it--;
				if( *r_it == 0 || *r_it < *target_it )	{ r_it = histogram.begin(); }
				else { connected++; }
			}
		}
		*/
		if( (*target_it) * connected >= maxArea ) {
			maxArea = (*target_it) * connected;
		}
		//cout << "connected: " << connected << endl;
	}
	result.push_back( maxArea );
	histogram.clear();
}

int main(void) {
	ll rect_cnt, height;
	
	while( 1 ){
		scanf("%lld", &rect_cnt);
		//cout << "���簢�� ����: " << rect_cnt << endl;
		if(rect_cnt == 0) { break; }
		
		for(int i=0; i<rect_cnt; i++) {
			scanf("%lld", &height);
			histogram.push_back( height );	// ���Ϳ� ���� �� ���� 
		}
		solve( rect_cnt );
		//cout << *max_element( area.begin(), area.end() ) << endl;
		area.clear();	
	}
	
	for(auto s: result) { printf("%lld\n", s); }
	return 0;
}

