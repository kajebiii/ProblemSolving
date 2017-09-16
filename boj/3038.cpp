#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_NN = (1<<15) + 10;
int N, Nr[MAX_NN], Memo[MAX_NN];
void printAns(int v)
{
	if(v >= (1<<N)) return;
	printf("%d ", Nr[v]);
	printAns(v*2);
	printAns(v*2+1);
}
int main()
{
	scanf("%d", &N);
	Nr[1] = 1;
	for(int n=2; n<=N; n++)
	{
		for(int i=1; i<(1<<n-1); i++) Memo[i] = Nr[i];
		for(int l=2, cnt=0; l<=n; l++) for(int i=(1<<l-1)+(1<<l-2); i<(1<<l); i++)   Nr[i] = Memo[++cnt] * 2;
		for(int l=2, cnt=0; l<=n; l++) for(int i=(1<<l-1); i<(1<<l-1)+(1<<l-2); i++) Nr[i] = Memo[++cnt] * 2;
		for(int i=(1<<n-1); i<(1<<n-1)+(1<<n-2); i++) Nr[i]++;
		for(int l=2; l<n; l++) for(int i=(1<<l-1)+(1<<l-2); i<(1<<l); i++) Nr[i]++;
	}
	printAns(1);
	return 0;
}