// 4ms 

#include <iostream>
#include <fstream>

using namespace std;

bool prison[101];
 
void set_prison(void) {
	for(int i=1;i<=100;++i) {
		for(int j=i;j<=100;j+=i) {
			prison[j]=!prison[j];			
		}		
	}
}

int get_num_escaper(int n) {
	int cnt=0;
	
	for(int i=1;i<=n;++i)
		if(prison[i])
			++cnt;	
	return cnt;
}

int main(void)
{
	int test_case, n;
	
	cin >> test_case;

	prison[0]=0;
	set_prison();
	
	for(int i=0;i<test_case;++i) {
		cin >> n;
		cout << get_num_escaper(n) << endl;
	}

	return 0;
}
