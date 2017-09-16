#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

const int MAX_N = 15, MAX_L = 1e2, MAX_K = 1e2 + 10;

int Pow[MAX_L], K;
int N, Nr[MAX_N], Cnt[MAX_N]; char getNr[MAX_N][MAX_L];

bool Visit[1<<MAX_N];
ll Dy[1<<MAX_N][MAX_K];
ll ggcd(ll a, ll b) {return b?ggcd(b, a%b):a;}

void getDy(int s)
{
	if(Visit[s] || s == 0) return;
	Visit[s] = true;
	for(int i=0; i<N; i++)
	{
		int val = s & (1<<i);
		if(val == 0) continue;
		int past = s - val;
		getDy(past);
		for(int k=0; k<K; k++)
		{
			int nk = (k * Pow[Cnt[i]] + Nr[i]) % K;
			Dy[s][nk] += Dy[past][k];
		}
	}
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s", getNr[i]);
	scanf("%d", &K);
	for(int i=0; i<N; i++)
	{
		Cnt[i] = strlen(getNr[i]);
		for(int k=0; k<Cnt[i]; k++)
		{
			Nr[i] *= 10;
			Nr[i] += getNr[i][k] - '0';
			Nr[i] %= K;
		}
	}
	Pow[0] = 1;
	for(int i=1; i<MAX_L; i++)
		Pow[i] = Pow[i-1] * 10 % K;
	Dy[0][0] = 1;
	getDy( (1<<N) - 1 );

	int last = (1<<N) - 1;
	ll a = Dy[last][0], b = 0;
	for(int i=0; i<K; i++) b += Dy[last][i];
	ll g = ggcd(a, b);
	printf("%lld/%lld\n", a/g, b/g);
	return 0;
}