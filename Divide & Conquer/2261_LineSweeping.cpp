//2261 ���� ����� �� �� 
//	4352KB	424ms 	C++14 	1540B
// Line Sweeping �� Ȱ��
// binary search�� ������ STL set�� upper_bound, lower_bound ��� 

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
			if( points[i].X - points[base].X <= Min) break; // �˻��� �� �߰�	
			else { // x�� ���̰� ���� �ּ� ���̸� ������ �˻��� �ʿ� x, base�� �ű��. 
				bases.erase(pi(points[base].Y, points[base].X));
				base++; 
			}
		}
		
		//�˻��� ���� �����κ��� +- sqrt(Min) ��ŭ ������ �ִ� ���� ���� �Ÿ��� check�Ѵ� ,
		// set���� �˻��� ������ ū x��ǥ�� ���� �� ���� �ʴ�.
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
