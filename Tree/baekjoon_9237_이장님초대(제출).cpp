/*
    memory: 2246KB
    time:   44ms
    lang:   C++11

*/
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;


class Farmer {
    static constexpr size_t MAX_TREE_COUNT = 100000;
    typedef array<int,MAX_TREE_COUNT> FarmerArray;
    typedef FarmerArray::iterator TreeIter;
    int treeCount;
    int allGrownUpTerm;
    FarmerArray trees;
    TreeIter treesBegin;
    TreeIter treesEnd;

    int countTree(TreeIter& target) {
        int count = 0;
        const int height = *target;
        bool same = height == *target;
        while(same){
            ++count;
            ++target;
            same = height ==*target;
        }        
        return count;
    }
  public:
    Farmer(void):treeCount(0),allGrownUpTerm(0) {
//        cout << "construct" << endl;
    }
    void byeTree(void) {
        cin >> treeCount;
        for(size_t i=0; i<treeCount; ++i) {
            cin >> trees[i];
        }
        treesBegin = trees.begin();
        treesEnd = trees.begin()+treeCount;
        sort(treesBegin,treesEnd, greater<int>());
        ++allGrownUpTerm;
    }

    void treeGrownUp(void) {
        int plantTime = 0;
        int finishTime = 0;

        TreeIter currentTree= treesBegin;
        bool done = currentTree == treesEnd;
        while(!done) {

            int growth = *currentTree;
            int count =  countTree(currentTree);

            plantTime += count;
            finishTime = max(finishTime, plantTime + growth);

            done = currentTree == treesEnd;
        }
        allGrownUpTerm += finishTime;
    }
    int inviteDay(void) {
        return allGrownUpTerm;
    }
};

//constexpr size_t Farmer::MAX_TREE_COUNT;

int main(void) {
    Farmer sangGeunLee;
    sangGeunLee.byeTree();
    sangGeunLee.treeGrownUp();
    cout <<sangGeunLee.inviteDay();
    return 0;
}