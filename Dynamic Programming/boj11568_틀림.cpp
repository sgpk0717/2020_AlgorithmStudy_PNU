// ���� 11568�� <�α����� �跫>
// �޸�: 			�ð�:  
#include <iostream>
#include <vector> 
using namespace std;

vector< int > Card;
int card_N;

int find_sequence() {
	int maxlen = 1;
	int length = 1;
	for(int i=0; i<card_N-1; i++) {
		if( Card[i+1] > Card[i] ) {
			length++;
			if(length > maxlen) { maxlen = length; }
		}
		else {
			length = 1;
		}	
	}
	
	return maxlen;
}

int main(void) {
	int number;

	cin >> card_N;
	for(int i=0; i<card_N; i++) {	// �ϴ� ���Ϳ� �� ���� 
		cin >> number;
		Card.push_back(number);
	}
	
	cout << find_sequence();
	return 0;
}

