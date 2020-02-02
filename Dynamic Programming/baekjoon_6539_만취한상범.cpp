/*
    memory: 1984KB
    time: 4ms
    language: C++11
    code length: 1642B

    �ǹ���: caseResult�� vector<int>���������� �ϸ� ����
        main ���� int�迭 ���������� �ϸ� runtime error �߻�(������ ���� ����)
    ����:
    v2
        goOnRound ���� for��
        ��: i=1���� ++i(�� 1����) �׸��� ���ȣ�� ���� ������� Ȯ��
        ��: i=round���� i+=round�� �ǳʶ�
    ���> time: 8ms -> 4ms, length: 1642B -> 1542B
    v3 
        ����̰� ������ ������ �κ��� �ٽ� ���ϵ��� ����(������ ���� ��� �״�� ���)
        drunkenSangBum ����
            goOnRound ȣ������ ���� �ȵ��ƺ� ��� �߿� round�� ����� �ּҸ� ���� 
            goOnRound �� ���ڷ� ����
            round���࿡�� ����̰� ���� ���� ���� �������� ���
    ���> length: 1981B -> 2091B
    
        v2 vs v3
        ������ �κ� �ٽ� ����(ȿ�� ���), ����� �ּ� ����(ȿ�� ����) -> ���...

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