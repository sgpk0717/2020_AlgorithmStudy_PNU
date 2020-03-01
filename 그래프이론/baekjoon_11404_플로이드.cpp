/*
    memory: 1984KB
    time:   200ms
    lang:   C++11
    
    
*/
#include <iostream>
#include <vector>

using namespace std;

class Floyd {
    static constexpr int UNKNOWN = 0;
    vector<vector<int>> busFare;
    vector<vector<int>> minimumFare;
private:
    void setBusSize(void) {
        size_t cityCount;
        cin >> cityCount;
        busFare.resize(cityCount+1);
        for(vector<int>& fare: busFare)
            fare.resize(cityCount+1);
    }
    void setBus(void) {
        size_t busCount;
        cin>>busCount;
        for(size_t i=0; i<busCount; ++i) {
            int start,arrive,fare;
            cin >>start>>arrive>>fare;
            bool noBus = busFare[start][arrive]==UNKNOWN;
            bool cheaper = busFare[start][arrive] > fare;
            if(noBus || cheaper) 
                busFare[start][arrive] = fare;
        }
    }
    void setMinimumFare(void) {
        minimumFare = busFare;
//        print();
    }
  public:
    Floyd(void) {
        setBusSize();
        setBus();
        setMinimumFare();
    }
    void solve(void) {
        for(size_t start=1; start<busFare.size(); ++start) {
            for(size_t edgeCount=1; edgeCount<busFare.size()-2; ++edgeCount) { // 직행 요금 적용되어 있음,최장 길이 도시개수 -1(최장 non-cycle path)
                for(size_t stopover=1; stopover<busFare.size(); ++stopover) {
                    bool stopoverNoBus = minimumFare[start][stopover] == UNKNOWN;
                    if(stopoverNoBus)
                        continue;

                    for(size_t arrive=1; arrive<busFare.size(); ++arrive) {
                        bool arriveIsStart = arrive == start;
                        if(arriveIsStart)
                            continue;
                        bool arriveNoBus = busFare[stopover][arrive] == UNKNOWN;
                        if(arriveNoBus)
                            continue;
                        const int currentFare = minimumFare[start][arrive];
                        const int newFare = minimumFare[start][stopover] + busFare[stopover][arrive];
                        bool cheaper = (currentFare > newFare) || (currentFare == UNKNOWN);
                        if(cheaper)
                            minimumFare[start][arrive] = newFare;
//                        cout << "(start,stopover,arrive) = ("<< start<<","<<stopover<<","<<arrive<<")"<<endl;
//                        cout << "current = "<< currentFare<<endl;
//                        cout << "new = " << newFare << endl;
                    }
                }
            }
        }
    }
    void print(void) {
        for(size_t i=1;i<minimumFare.size();++i){
            for(size_t j=1;j<minimumFare.size();++j){
                cout << minimumFare[i][j] << " ";
            }
            cout <<endl;
        }
    }
};
//int Floyd::UNKNOWN;

int main(void) {
    Floyd problem;
    problem.solve();
    problem.print();
    return 0;
}
