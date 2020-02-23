/*
    memory: 1980KB
    time:   0ms
    lang: C++11
*/


#include <iostream>

using namespace std;

class University {
    int countGirl;
    int countBoy;
    int countIntern;

    int getCountGirl(void) {
        return countGirl;
    }
    int getCountBoy(void) {
        return countBoy;
    }
    int getCountIntern(void) {
        return countIntern;
    }
  public:
    University(void) {
        cin >> countGirl >> countBoy >> countIntern;
    }
    int getTeamCount(void) {
        const int possibleTeamCount = min(getCountGirl()/2, getCountBoy());
        const int needMoreIntern = countIntern - (getCountGirl()+getCountBoy() -possibleTeamCount*3);
        bool enoughIntern = needMoreIntern <= 0;
        if(enoughIntern) {
            return possibleTeamCount;
        }
        const int exceptedTeamCount = needMoreIntern%3 ? needMoreIntern/3+1: needMoreIntern/3;
        return possibleTeamCount - exceptedTeamCount;
    }

};

int main(void) {
    University baekJoon;
    cout << baekJoon.getTeamCount();
    return 0;
}