#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int maxN = 100; ll minV[222] = {0, -1};
int How[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
	for(int i=2; i<=maxN; i++)
	{
		minV[i] = -1;
		for(int j=0; j<10; j++)
		{
			if(i - How[j] < 0) continue;
			if(minV[i-How[j]] == -1) continue;
			if(minV[i] == -1)
				minV[i] = minV[i-How[j]] * 10 + j;
			else 
				minV[i] = min(minV[i], minV[i-How[j]] * 10 + j);
		}
		if(i == 6) minV[i] = 6;
	}
	int N; scanf("%d", &N);
	for(int _=0; _<N; _++)
	{
		int x; scanf("%d", &x);
		printf("%lld ", minV[x]);
		if(x % 2 == 1) printf("7"), x -= 3;
		for(; x>0; x-=2) printf("1");
		printf("\n");
	}
	return 0;
}