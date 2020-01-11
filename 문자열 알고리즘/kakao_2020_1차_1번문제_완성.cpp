/* īī�� 2020 ���� ������ ����ε� ä�� 1�� �ڵ� �׽�Ʈ ����1  �ð�: 7.51ms */
#include <string>
using namespace std;
int compress( string data, int unit);
/*
int main(void) {
    string s;   cin >> s;
    cout << solution(s);
}
*/
int solution(string s) {
    int data_size = s.size();
    int min_size = data_size;

    for(int i=1; i <= data_size/2; i++){          // ���� ������ 1~(���ڿ� ���� ���� )
        int compress_size = compress(s, i);
        if(compress_size < min_size) {          // ���� �� ���ö����� min�� ��ü
            min_size = compress_size;
        }
    }

    return min_size;
}

int compress( string data, int unit ) {
    int compressed_size = 0;
    int data_size = data.size();
    int remainder = data_size%unit;     // ������ ������ ���� ������ string

    size_t pos = 0;
    while( pos < data_size - remainder ){
        int overlap_cnt = 0;            // ���� ���ڿ� �ߺ� Ƚ��
        string target = data.substr(pos, unit);
        overlap_cnt++;
        pos += unit;

        while( target == data.substr(pos, unit) ) {   // target string�̶� ������ ��� �ִ���
            overlap_cnt++;
            pos += unit;
        }

        if(overlap_cnt > 1){
            cout << overlap_cnt;
            compressed_size += ( to_string(overlap_cnt).size() );   // �ι� �̻� �Ȱ����� ������ ��� ��ģ Ƚ�� ������ ���� ����
        }
        cout << target;
        compressed_size += target.size();   // substring�� ���� ����
    }
    cout << remainder;
    compressed_size += remainder;           // ������ ������ ���� ���ڿ� ���� ����

    return compressed_size;
}
