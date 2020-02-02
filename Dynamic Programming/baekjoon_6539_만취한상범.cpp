/*
    memory: 1984KB
    time: 4ms
    language: C++11
    code length: 1642B

    의문점: caseResult를 vector<int>전역변수로 하면 맞음
        main 안의 int배열 지역변수로 하면 runtime error 발생(예제는 문제 없음)
    수정:
    v2
        goOnRound 내부 for문
        전: i=1부터 ++i(방 1개씩) 그리고 방번호가 라운드 배수인지 확인
        후: i=round부터 i+=round로 건너뜀
    결과> time: 8ms -> 4ms, length: 1642B -> 1542B
    v3 
        상범이가 게임을 진행한 부분은 다시 안하도록 수정(이전에 구한 결과 그대로 사용)
        drunkenSangBum 내부
            goOnRound 호출전에 아직 안돌아본 방들 중에 round의 배수중 최소를 구함 
            goOnRound 에 인자로 전달
            round진행에서 상범이가 도는 방의 범위 시작으로 사용
    결과> length: 1981B -> 2091B
    
        v2 vs v3
        진행한 부분 다시 안함(효율 상승), 배수중 최소 구함(효율 감소) -> 상쇄...

*/

#include <iostream>
#include <vector>

using namespace std;

constexpr bool opened = true;
constexpr bool closed = false;
constexpr size_t ROOM_COUNT_MAX = 101;// use index 1~100

bool rooms[ROOM_COUNT_MAX];
vector<int> caseResults;

void closeRoom(const int roomCount) {
    for(size_t i=1; i<=roomCount; ++i) {
        rooms[i] = closed;
    }
}

void goOnRound(const int round, const int roomCount) {
    for(size_t i=round; i<=roomCount; i+=round) {
        const bool isRoomClosed = rooms[i] == closed;
        if(isRoomClosed) {
            rooms[i] = opened;
        } else {
            rooms[i] = closed;
        }

    }
}
void drunkenSangBum(const int roomCount) {
    closeRoom(roomCount);
    for(size_t i=1; i<=roomCount; ++i) {
        goOnRound(i,roomCount);
    }
}
int getEscapedCount(const int roomCount) {
    int result=0;
    for(size_t i=1; i<=roomCount; ++i) {
        const bool isRoomOpened = rooms[i]; //"rooms[i] == opened" equals "rooms[i]"
        if(isRoomOpened) {
            ++result;
        }
    }
    return result;
}
void getResult(const int caseCount) {
    for(size_t i=0; i<caseCount; ++i) {
        int roomCount;
        cin >> roomCount;
        drunkenSangBum(roomCount);
        caseResults.push_back(getEscapedCount(roomCount));
    }
}
void printResult(const int caseCount) {
    for(size_t i=0; i<caseCount; ++i) {
        cout << caseResults[i] << endl;
    }
}
int main(void) {
    int caseCount;

    cin>>caseCount;

    getResult(caseCount);

    printResult(caseCount);

    return 0;
}