// 0ms

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> cards(1001);
vector<int> longest(1001);

int cal_longest(int n) {
	int v;
	int max_value=0;
	
	longest[0]=0;
	longest[1]=1;
	
	for(int i=1;i<=n;++i) {	
//		printf("=============%d번째,카드 %d===========\n",i,cards[i]); 
		v = cards[i];
		
		for(int j=i-1;j>=0;--j) 
			if(v>cards[j]) {
//				printf("%d번째 카드 %d가 %d번째 카드 %d보다 작으므로 카운트 증가.\n",j,cards[j],i,cards[i]); 
				longest[i]=max(longest[i],longest[j]+1);
			}
		max_value = longest[i] > max_value ? longest[i] : max_value;	
	}
	return max_value;
}

int main(void)
{
	cin >> N;
	for(int i=1;i<=N;++i)
		cin >> cards[i];
	
	cout << cal_longest(N) << endl;	
	
	return 0;
}
