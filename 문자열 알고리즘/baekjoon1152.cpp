/* ���� 1152   �ð�: 40ms */
// ó���� empty string�� ��� ���ؼ� Ʋ�Ⱦ���. ���� �ϳ� �Էµ� ����ؾ���
#include <iostream>
#include <string>
using namespace std;

int main(void){
    string sentence;
    int word_cnt = 0;

    getline(cin, sentence, '\n');

    size_t pos = sentence.find_first_not_of(' ');   // ó������ ������ �ƴ� ��ġ
    while( pos != sentence.find_last_not_of(' ') ){ // ���������� ������ �ƴ� ��ġ����
        if( sentence[pos] == ' ' )     // ù �ܾ�� ������ �ܾ� ���� ���� ī��Ʈ
            word_cnt++;
        pos++;
    }

    if( !(sentence.empty() || sentence == " ") )    // empty string�̳� ���� �ƴϸ�
        word_cnt++;                                 // ī��Ʈ 1 ����
    cout << word_cnt;

	return 0;
}
