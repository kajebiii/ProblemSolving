#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_K = 111;
const int MAX_N = 1e5 + 100;
const int INF = 0x7fffffff;

int K, N;
ll Prime[MAX_K];
int Memo[MAX_N];
int Index[MAX_K];
int main()
{
	scanf("%d%d", &K, &N);
	Memo[0] = 1;
	for(int i=0; i<K; i++) scanf("%lld", &Prime[i]);
	for(int i=0; i<K; i++) Index[i] = 0;

	for(int i=1; i<=N; i++)
	{
		ll nowMin = 1ll * INF * INF;
		for(int j=0; j<K; j++)
			nowMin = min(nowMin, Prime[j] * Memo[Index[j]]);
		Memo[i] = nowMin;
		for(int j=0; j<K; j++)
			if(nowMin == Prime[j] * Memo[Index[j]])
				Index[j]++;
	}
	printf("%d", Memo[N]);
	return 0;
}