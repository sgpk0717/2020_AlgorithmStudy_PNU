#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> calory;	// 1원부터 상근이가 가진 돈까지 1원씩 증가시키면서 칼로리를 계산. 
vector< int > candy; // 캔디의 정보를 저장. 이때 가격별로 정해진 인덱스에 저장. 
vector<bool> check; // 정해진 인덱스에 캔디의 정보가 저장되었는지를 체크해주는 배열. 
vector< pair<int,int> > rcandy; // 중복 제거된 캔디. 

bool compare(const pair<int,int>& p1, const pair<int,int>& p2) {
	return p1.second < p2.second;	
}

void set_list_of_candy(void) {
	for(int i=1;i<=10000;++i)
		if(check[i])
			rcandy.push_back(pair<int,int>(candy[i],i));
	sort(rcandy.begin(),rcandy.end(),compare);
}

void print_calory(int money) {
	for(int i=0;i<=money;++i)
		printf("%d원일때: %d\n",i,calory[i]); 
	cout << endl;
}

void print_candy(void) {
	for(int i=0;i<rcandy.size();++i) {
		printf("(%d,%d) ",rcandy[i].first,rcandy[i].second);
	}
	cout << endl;
}

void cal_highest_calory(int money) {
	for(int i=1;i<=money;++i) {
		for(int j=0;j<rcandy.size();++j) {
			if(i-rcandy[j].second<0) break;
			calory[i]=max(calory[i],calory[i-rcandy[j].second]+rcandy[j].first);
		}
	}

//	for(int i=0;i<rcandy.size();++i) 
//		for(int j=rcandy[i].second;j<=money;++j) 
//			calory[j]=max(calory[j],calory[j-rcandy[i].second]+rcandy[i].first);	
		
	
}

int main(void)
{
	int n,c;
	double m,p;
	int index;
	
	while(cin >> n >> m) {
		if(n==0) break;
		int money = (int)(m*100.00);
		candy.clear();
		check.clear();
		calory.clear();
		rcandy.clear();
		
		calory.resize(money+1);
		candy.resize(10001);
		check.resize(10001);
		
		for(int i=0;i<n;++i) {
			cin >> c >> p;
			index = (int)(p*100.00);
			if(!check[index]) {
				check[index]=true;
				candy[index]=c;	
			} else {
				candy[index]=candy[index] < c ? c : candy[index];
			}
		}
		set_list_of_candy();
		//print_candy();
		cal_highest_calory(money);
		//print_calory(money);
		
		cout << calory[money] << endl;
	}
	
	return 0;
}
