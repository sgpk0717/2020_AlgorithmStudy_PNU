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
//		printf("=============%d��°,ī�� %d===========\n",i,cards[i]); 
		v = cards[i];
		
		for(int j=i-1;j>=0;--j) 
			if(v>cards[j]) {
//				printf("%d��° ī�� %d�� %d��° ī�� %d���� �����Ƿ� ī��Ʈ ����.\n",j,cards[j],i,cards[i]); 
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
