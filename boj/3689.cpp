#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 100;

int S, N, Nr[MAX_N];
int Good[MAX_N], Bad[MAX_N];
int Cnt[MAX_N], Possible[MAX_N], Perfect[MAX_N], PoS, PeS;
void chCnt(int g, int n, int k)
{
	int ix = g * S + n;
	Cnt[ix] += k;
//	printf(">>%d %d -> %d\n", g, n, Cnt[ix]);
	if(Cnt[ix] == 1) 
	{
		Good[g]++;
		if(k == -1) Bad[g]--;
		if(Perfect[g] == 0 && Good[g] == S && Bad[g] == 0) Perfect[g] = 1, PeS++;
		if(Possible[g] == 0 && Bad[g] == 0) Possible[g] = 1, PoS++;
	}
	if(Cnt[ix] == 2 && k == 1)
	{
		if(Perfect[g] == 1) Perfect[g] = 0, PeS--;
		if(Possible[g] == 1) Possible[g] = 0, PoS--;
		Good[g]--;
		Bad[g]++;
	}
	if(Cnt[ix] == 0)
	{
		if(Perfect[g] == 1) Perfect[g] = 0, PeS--;
		Good[g]--;
	}
}
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &S, &N);
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);

		int allG = (N - 1 - 1) / S + 2;
		for(int i=1; i<=allG; i++)
		{
			Perfect[i] = 0; PeS = 0;
			Possible[i] = 1; PoS = allG;
			Good[i] = Bad[i] = 0;
		}
		for(int i=1; i<=allG*S+S; i++) Cnt[i] = 0;

		chCnt(1, Nr[1], 1);
		for(int i=2; i<=N; i++) chCnt((i-2)/S + 2, Nr[i], 1);

		int ans = 0;
		for(int k=1; k<=S; k++)
		{
			int l = 1, r = (N + (S-k-1) ) / S + 1;
			if(k != 1)
			{
				for(int i=k; i<=N; i+=S) chCnt((i-k)/S+1, Nr[i], 1);
				for(int i=k; i<=N; i+=S) chCnt((i-k)/S+2, Nr[i], -1);
			}
//			for(int i=l; i<=r; i++) printf("%d : [%d %d] %d %d\n", i, Good[i], Bad[i], Possible[i], Perfect[i]);
			if(Possible[l] == 1 && Possible[r] == 1)
			{
				int other = PeS - Perfect[l] - Perfect[r];
				if(l == r) 
				{
					other += Perfect[l];
					if(other == 0) ans++;
				}
				else if(other == (r-l-1)) ans++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}