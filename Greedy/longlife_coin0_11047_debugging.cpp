#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void print_coin(vector<int>& coin)
{
	cout << "------------------------------ coin ------------------------------" << endl;
	for(int i=0;i<coin.size();++i)
		cout << coin[i] << '\t';
	cout << endl << "------------------------------ coin ------------------------------" << endl << endl;
}

void processing(istream& is)
{
	int N, price, tmp, cnt_coin=0;
	vector<int> coin;
	
	is >> N >> price >> tmp;
	cout <<"tmp : " << tmp << endl;
	for(int i=0;i<N && !(price < tmp);++i){
		coin.push_back(tmp);
		is >> tmp;
		cout << "tmp : " << tmp << endl;
	}
	print_coin(coin);
	
	for(int i=coin.size()-1;i>=0 && !(price==0) ;--i){
		while(coin[i]<=price){
			price -= coin[i];
			cnt_coin++;
		}
	}
	cout << "cnt_coin : " << cnt_coin << endl;
}


int main(void)
{
   const char* ifn = "coin0_11047_3.txt";
   
   ifstream ifs(ifn);
   if(!ifs.is_open()){
      cerr << "Error: the input file cannot be opened." << endl;
      return -1;
   }
   
   processing(ifs);
   
   ifs.close();
    
   return 0;
}

