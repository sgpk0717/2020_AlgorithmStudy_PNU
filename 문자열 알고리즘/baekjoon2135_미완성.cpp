#include <iostream>
#include <string>
using namespace std;
// �α��� �ܾ 2�� �����°� ���� ���ϴ°� �� ª��
/*
 * pos1�� �� ������ �Ǵ� substring�� ���� �ε�����.
 * ���� �ܾ���� �����ϴ� substring �� ���̰� ���� �� ��(���� string�� ���ݱ���)����
 * �ٷ� ���� �ܾ�� ������ ����.
 * ���� ���, "mamapapa"�� mama���� mam, ma...Ž���ϰ�
 * ama, am....
 * map, ma...
 * ap....
*/

void compress(string data) {
    int data_size = data.size();
    int cnt = 0;
    size_t pos1 = 0;

    while( pos1 < data_size-1 ) {
        size_t pos2 = pos1 + (data_size-pos1)/2;

        while( pos1 != pos2 ) {
            int interval = pos2 - pos1;
            if( data.substr(pos1, interval) == data.substr(pos2, interval) ){
                cout << data.substr(pos1, interval) << ' ' << pos1 << endl;
                cnt++;
                pos1 += interval;
                pos2 += interval;
              //  break;
              }
            else { pos2-- ; }
        }
        cout << cnt << endl;
        cnt = 0;
        pos1++;
    }
}

int main(void){
    cout << "0123456789012345678901234567890123456\n";
    string data;
    cin >> data;
    compress(data);

	return 0;
}
