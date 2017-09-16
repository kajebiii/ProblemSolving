#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 25e2 + 100;

int N; ll Nr[MAX_N][2];
vector<ll> Val;
vector<int> Ed[MAX_N];
bool Visit[MAX_N]; int MatchB[MAX_N * 3], MatchA[MAX_N];
int getIx(ll nr)
{
	return lower_bound(Val.begin(), Val.end(), nr) - Val.begin();
}
bool isMatch(int v)
{
	if(Visit[v]) return false;
	Visit[v] = true;

	for(int w : Ed[v])
		if(MatchB[w] == 0 || isMatch(MatchB[w]))
		{
			MatchB[w] = v;
			MatchA[v] = w;
			return true;
		}
	return false;
}

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%lld%lld", &Nr[i][0], &Nr[i][1]);
	for(int i=1; i<=N; i++)
	{
		Val.push_back(Nr[i][0] + Nr[i][1]);
		Val.push_back(Nr[i][0] - Nr[i][1]);
		Val.push_back(Nr[i][0] * Nr[i][1]);
	}
	sort(Val.begin(), Val.end());
	Val.erase(unique(Val.begin(), Val.end()), Val.end());
	for(int i=1; i<=N; i++)
	{
		Ed[i].push_back(getIx(Nr[i][0] + Nr[i][1]));
		Ed[i].push_back(getIx(Nr[i][0] - Nr[i][1]));
		Ed[i].push_back(getIx(Nr[i][0] * Nr[i][1]));
	}

	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++) Visit[j] = false;
		if(isMatch(i)) ans++;
	}
	if(ans != N) puts("impossible");
	else
	{
		for(int i=1; i<=N; i++)
		{
			char c[3] = {'+', '-', '*'};
			ll val[3] = {Nr[i][0] + Nr[i][1], Nr[i][0] - Nr[i][1], Nr[i][0] * Nr[i][1]};
			for(int k=0; k<3; k++)
				if(Val[MatchA[i]] == val[k])
				{
					printf("%lld %c %lld = %lld\n", Nr[i][0], c[k], Nr[i][1], val[k]);
					break;
				}
		}
	}
	return 0;
}