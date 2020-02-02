#include <iostream>

using namespace std;

int main(void){
    int n;
    unsigned long long a1=0,a2=1;
    unsigned long long an;
    cin >> n;
    for(int i=0;i<n;++i){
        an = (a1 + a2) % 10007;
        a1 = a2;
        a2 = an;
        
    }
    cout << an;
    
    return 0;
}