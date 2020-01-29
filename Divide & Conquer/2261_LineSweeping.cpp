//2261 가장 가까운 두 점 
//	4352KB	424ms 	C++14 	1540B
// Line Sweeping 을 활용
// binary search로 구현된 STL set의 upper_bound, lower_bound 사용 

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

#define X first
#define Y second

using namespace std;

typedef pair<int,int> pi; 

int dist(pi a, pi b){ 
	return pow(b.Y-a.Y , 2) + pow(b.X - a.X , 2);
}

int main(void){
	int n;
	set<pi> bases; 
	vector<pi> points;
	
	cin >> n;
	
	for(size_t i=0; i<n; i++){
		int x,y;
		cin >> x >> y;
		points.push_back(make_pair(x,y));
	}
	
	sort(points.begin(), points.end());
	
//	for(size_t i=0; i<n; i++){
//		cout << starts[i].X << " " << starts[i].Y <<endl;
// 	}

	int Min = dist(points[0], points[1]);
	int base = 0;
	bases.insert(pi(points[0].Y, points[0].X)); 
	bases.insert(pi(points[1].Y, points[1].X));
	
	for(size_t i=2; i<n; i++){
		while( base < i ){
			if( points[i].X - points[base].X <= Min) break; // 검사할 점 발견	
			else { // x값 차이가 현재 최소 길이를 넘으면 검사할 필요 x, base를 옮긴다. 
				bases.erase(pi(points[base].Y, points[base].X));
				base++; 
			}
		}
		
		//검사할 점과 점으로부터 +- sqrt(Min) 만큼 범위에 있는 점들 간의 거리를 check한다 ,
		// set에는 검사할 점보다 큰 x좌표의 점은 들어가 있지 않다.
		double limit = sqrt(Min);
		for(auto it=bases.lower_bound(pi(points[i].Y - limit, -INT_MAX ));  
		         it!=bases.upper_bound(pi(points[i].Y + limit, INT_MAX));  
				 it++ )
		{
			Min = min(Min, dist(pi(it->Y, it->X), points[i]));	
		} 
		bases.insert(pi(points[i].Y, points[i].X));
	}
	
	cout << Min;
	
	return 0;
}
