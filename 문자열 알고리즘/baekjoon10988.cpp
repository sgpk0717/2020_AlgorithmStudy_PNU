/* ���� 10988��    �ð� 0ms
* �����͸� �Է� �޾Ƽ� ����(�Ǵ� �迭)�� �����ϴ� �������� ������� ����
*/
#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 100

int main(void) {
    char word_arr[MAXSIZE] = {};        // �ܾ� ���� char �迭
    scanf("%100s", word_arr);           // 100���� �Է¹���

    int word_len = strlen(word_arr);    // �ܾ� ����

    int i = 0, j = word_len-1;          // i�� ��, j�� �ں��� Ž��
    while(i < j){
        if( word_arr[i] != word_arr[j] )
            break;
        i++;
        j--;
    }
    /*
    while�� �ȿ���
    if( word_arr[i++] != word_arr[j--] )
        break;
    �̷��� ¥�ϱ� �ܾ� ���̰� 2, 3�� �� ������ ����� 1�� ���ͼ� Ʋ�ȴ�.
    */

    int result = ( i < j ? 0 : 1 );
    printf("%d", result);

	return 0;
}
