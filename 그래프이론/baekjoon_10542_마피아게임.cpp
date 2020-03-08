#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#include <cassert>

using namespace std;

class Citizen {
  public:
    virtual bool isMafia(void) {
        return false;
    }
    virtual int mafiaCount(void) {
        return 0;
    }
};

class Mafia:public Citizen {
  public:
    bool isMafia(void)override {
        return true;
    }
    int mafiaCount(void) override {
        return 1;
    }
};
//struct PlayerCompare{
//    bool operator()(const Player& lhs, const Player& rhs){
//        return lhs > rhs;
//    }
//};
class Player {
    size_t number;
    Citizen* identity;
    Player* indicating;
    size_t indicatorCount;

    void setMafia(void) {
        if(identity == nullptr) {
            identity = new Mafia;
        }
        --(indicating->indicatorCount);
//        else if(!isMafia()){
//            delete identity;
//            identity = new Mafia;
//        }
    }
    void setCitizen(void) {
        if(identity == nullptr) {
            identity = new Citizen;
        }
        --(indicating->indicatorCount);
//        else if(!isMafia()){
//            delete identity;
//            identity = new Citizen;
//        }
    }
  public:
    void indicatorCountUp(void) {
        ++indicatorCount;
    }
    void print(void) {
        cout << number << ":";
        cout << "isMafia: " << boolalpha << isMafia() <<endl;
    }
    bool operator==(const Player& rhs) const {
        return indicatorCount == rhs.indicatorCount;
    }
    bool operator<(const Player& rhs) const {
        if(*this == rhs)
            return *indicating > *rhs.indicating;
        return this->indicatorCount < rhs.indicatorCount;
    }
    bool operator>(const Player& rhs) const {
        if(*this == rhs)
            return this->indicating->indicatorCount < rhs.indicating->indicatorCount;
        return this->indicatorCount > rhs.indicatorCount;
    }
    size_t getNumber(void)const {
        return number;
    }
    size_t getIndicatorCount(void)const {
        return indicatorCount;
    }
    void setNumber(const size_t number_) {
        number = number_;
    }
    void setIndicating(Player* indicating_) {
        indicating = indicating_;
    }

    bool identified(void)const {
        return identity!=nullptr;
    }
    bool isMafia(void)const {
        assert(identity!=nullptr);
        return identity->isMafia();
    }
    void mafia_or_citizen(void) {
//        cout << number << " indicate" << indicating->number<<endl;
        if(identified()) {
            return;
        }
        if(indicating->identified()) {
            if(indicating->isMafia()) {
                setCitizen();
                return;
            } else {
                setMafia();

            }
        } else {
            setMafia();
            indicating->setCitizen();
        }

    }
    int countUp(void)const {
        return identity->mafiaCount();
    }


};
class OrderInfo {
    Player* player;
//    size_t indicatorCount;
  public:
    bool operator<(const OrderInfo& rhs)const {
        return *player<*(rhs.player);
    }
    OrderInfo(Player& player)
        :player(&player) {
//        :player(&player),indicatorCount(player.getIndicatorCount()) {
    }
    Player& getPlayer(void) {
        return *player;
    }
};
class MafiaGame {
    vector<Player> player;


    void setMostMafia(void) {
        queue<Player*> unknownPlayer;
        // select target
        
        bool done = false;
        while(!done) {
            Player* minimumIndicated = nullptr;
            for(size_t i=1; i<player.size(); ++i) {
                if(player[i].identified()) {
                    continue;
                }
                if(player[i].getIndicatorCount()==0) {
                    unknownPlayer.push(&player[i]);
                }
            }
            if(unknownPlayer.empty()) {
                vector<OrderInfo> checkOrder;
                for(size_t i=1; i<player.size(); ++i) {
                    if(player[i].identified()) {
                        continue;
                    }
                    checkOrder.push_back(OrderInfo(player[i]));
                }
                sort(checkOrder.begin(),checkOrder.end());
                for(size_t i=0; i<checkOrder.size(); ++i)
                    checkOrder[i].getPlayer().mafia_or_citizen();
                done = true;
            }
            while(!unknownPlayer.empty()) {
                Player* candidate = unknownPlayer.front();
                unknownPlayer.pop();
                candidate->mafia_or_citizen();
            }
        }
    }

    int countMafia(void) {
        int result =0;
        for(size_t i=1; i<player.size(); ++i) {
            result += player[i].countUp();
        }
        return result;
    }
  public:
    MafiaGame(void) {
        size_t playerCount, indicated;
        cin>> playerCount;

        player.resize(playerCount+1);
        for(size_t i=1; i<player.size(); ++i) {
            player[i].setNumber(i);
            cin>>indicated;
            player[i].setIndicating(&player[indicated]);
            player[indicated].indicatorCountUp();
        }

    }
    int mostMafia(void) {
        setMostMafia();
//        for(size_t i=1; i<player.size(); ++i) {
//            player[i].print();
//        }
        return countMafia();
    }
};
int main(void) {
    MafiaGame game;
    cout << game.mostMafia();
    return 0;
}