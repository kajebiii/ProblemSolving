#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second
#define pb push_back

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, 1), mp(1, 0), mp(0, -1)};
const int MOD = 1e9 +7;

bool notP[1111];
int Chk[1111], Nr[1001001];
int main()
{
	int T, N; cin >> T;
	notP[1] = true;
	for(int i=2; i<=1000; i++)
		for(int j=2; j*j<=i; j++)
			if(i % j == 0) {notP[i] = true; break;}
	while(T--)
	{
		scanf("%d", &N); 
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
		for(int i=1; i<=N; i++)
		{
			for(int j=2; j*j<=Nr[i]; j++)
			{
				int getMax = 1;
				while(Nr[i] % j == 0) Nr[i] /= j, getMax *= j;
				Chk[getMax] = 1;
			}
			Chk[Nr[i]] = 1;
		}
		long long ans = 1;
		for(int i=2; i<=1000; i++)
		{
			if(notP[i] == true) continue;
			int now = i, nowmax = 1;
			while(now <= 1000)
			{
				if(Chk[now] == 1) nowmax = now;
				now *= i;
			}
			ans = (ans * nowmax) % MOD;
		}
		printf("%lld\n", ans);
		for(int i=2; i<=1000; i++)
		{
			if(notP[i] == true) continue;
			int now = i;
			while(now <= 1000)
				Chk[now] = 0, now *= i;
		}
	}
	return 0;
}
