/*
    memory: 1984KB
    time:   56ms
    lang:   C++11
*/

#include <iostream>
//#include <cassert>

using namespace std;

class CoinCombiner{
    int* coins;
    int sum;
    int kindCount;
    
    static int* getCoins(const int kindCount){
        int* result = new int[kindCount];
        for(int i=0;i<kindCount;++i){
            cin >> result[i];
        }
        return result;
    }
    int getCoinAt(size_t index){
//        assert(index<kindCount);
        return coins[index];
    }
public:
    CoinCombiner(void){
        cin >> kindCount >>sum;
        coins = getCoins(kindCount);
    }
    int solve(void){
        int coinCount = 0;
        int partSum = 0;
        size_t possibleBiggest = kindCount - 1;
        bool done = false;
        while(!done){
            bool isExcess = (sum-partSum) < getCoinAt(possibleBiggest);
            if(isExcess){
                --possibleBiggest;
            }
            else{
                partSum += getCoinAt(possibleBiggest);
                ++coinCount;
            }
            done = sum == partSum;
        }
        return coinCount;
    }
};
int main(void)
{
    CoinCombiner joonGyu;
    cout << joonGyu.solve();
    return 0;
}