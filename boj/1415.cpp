#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

const int MAX_NR = 5e5, MAX_N = 55;

bool notP[MAX_NR+1];
int N, Nr[MAX_N];
long long Dy[2][MAX_NR+1];

int main()
{
	scanf("%d", &N);
	int sum = 0;
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]), sum += Nr[i];
	sort(Nr, Nr+N);

	notP[0] = true;
	notP[1] = true;
	for(int i=2; i<=sum; i++) if(notP[i] == false)
		for(int j=i*2; j<=sum; j+=i) notP[j] = true;

	int maxIx = 0;
	Dy[0][0] = 1;
	int ix = 0;
	for(int i=0, j; i<N; i=j)
	{
		ix = 1 - ix;
		int o = 1 - ix;
		j = i;
		int cnt = 0;
		while(j < N && Nr[i] == Nr[j]) cnt++, j++;
		memset(Dy[ix], 0, sizeof(long long)*(maxIx+1));
		for(int p=maxIx; p>=0; p--)
		{
			if(Dy[o][p] == 0) continue;
			for(int k=0; k<=cnt; k++)
			{
				Dy[ix][p+k*Nr[i]] += Dy[o][p];
				maxIx = max(maxIx, p+k*Nr[i]);
			}
		}
	}
	long long ans = Dy[ix][2];
	for(int i=3; i<=sum; i+=2) if(notP[i] == false) ans += Dy[ix][i];
	printf("%lld\n", ans);
	return 0;
}