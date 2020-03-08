/*
    memory: 17788KB
    time:   524ms
    lang:   C++11

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Future {
    class Tube {
        size_t distance;
        vector<int> station;
      public:
        void resize(size_t size_) {
            station.resize(size_);
        }
        bool isVisited(void) {
            return distance>0? true:false;
        }
        vector<int>& getStation(void) {
            return station;
        }
        void setDistance(size_t distance_) {
            distance = distance_;
        }
        size_t getDistance(void) {
            return distance;
        }
    };
    class Station {
        size_t distance;
        vector<int> tube;
      public:
        void add(const int newTube) {
            tube.push_back(newTube);
        } bool isVisited(void) {
            return distance>0? true:false;
        }
        const vector<int>& getTube(void) {
            return tube;
        }
        void setDistance(size_t distance_) {
            distance = distance_;
        }
        size_t getDistance(void) {
            return distance;
        }
    };
    vector<Station> stations;
    vector<Tube> tubes;

    int isConnected(const size_t start, const size_t destination) {
        if(start == destination)
            return 1;
        stations[start].setDistance(1);
        queue<size_t> nextStations;
        nextStations.push(start);
        bool isMoreStation = !nextStations.empty();
        while(isMoreStation) {
            size_t currentStation = nextStations.front();
            nextStations.pop();
            int currentDistance = stations[currentStation].getDistance();
            for(const int connectedTube: stations[currentStation].getTube()) {
                if(tubes[connectedTube].isVisited())
                    continue;
                tubes[connectedTube].setDistance(currentDistance);
                for(const int nextStation: tubes[connectedTube].getStation()) {
                    if(stations[nextStation].isVisited())
                        continue;
                    bool reachedDestination = nextStation == destination;
                    if(reachedDestination)
                        return currentDistance+1;
                    stations[nextStation].setDistance(currentDistance+1);
                    nextStations.push(nextStation);
                }
            }
            isMoreStation = !nextStations.empty();
        }
        return -1;
    }
  public:
    Future(void) {
        int stationCount,hypertubeSize,hypertubeCount;
        cin >> stationCount >> hypertubeSize >> hypertubeCount;
        stations.resize(stationCount+1);
        tubes.resize(hypertubeCount+1);
        for(Tube& tube: tubes)
            tube.resize(hypertubeSize);
    }
    void connectStation(void) {
        for(size_t tubeNumber=1; tubeNumber<tubes.size(); ++tubeNumber) {
            Tube& tube = tubes[tubeNumber];
            for(int& stationNumber: tube.getStation()) {
                cin >> stationNumber;
                stations[stationNumber].add(tubeNumber);
            }
        }
    }
    int solve(void) {
        return isConnected(1,stations.size()-1);
    }
};

int main(void) {
    Future transfer;
    transfer.connectStation();
    cout << transfer.solve();
    return 0;
}

