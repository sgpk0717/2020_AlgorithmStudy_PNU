// Memory : 1984 KB
// Time : 44 ms

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, price, tmp, cnt_coin=0;
	vector<int> coin;
	
	cin >> N >> price >> tmp;
	for(int i=0;i<N && !(price < tmp);++i){
		coin.push_back(tmp);
		cin >> tmp;
	}
	
	for(int i=coin.size()-1;i>=0 && !(price==0) ;--i){
		while(coin[i]<=price){
			price -= coin[i];
			cnt_coin++;
		}
	}
	cout << cnt_coin << endl;
    
   return 0;
}

