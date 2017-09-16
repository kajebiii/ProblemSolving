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
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };
const int MAX_N = 111;

int N, Cnt[MAX_N], Can[MAX_N];
vector<int> V[MAX_N];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N;
	for(int i=1; i<N; i++)
	{
		int x; scanf("%d", &x);
		for(int j=0, y; j<x; j++)
		{
			scanf("%d", &y);
			V[i].pb(y);
		}
	}
	queue<int> Q;
	Q.push(1); Can[1] = 1;
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		for(int &next : V[now])
			if(Can[next] == 0)
			{
				Q.push(next);
				Can[next] = 1;
			}
	}
	int CanN = 0;
	for(int i=1; i<=N; i++) if(Can[i] == 1) CanN++;
	for(int i=1; i<=N; i++) if(Can[i] == 1) for(int j : V[i]) Cnt[j]++;

	for(int i=1; i<=N; i++) if(Cnt[i] == 0 && Can[i] == 1) Q.push(i);
	int ans = 0;
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		ans++;
		for(int &next : V[now])
			if(Cnt[next]-- == 1 && Can[next] == 1)
				Q.push(next);
	}
	if(ans == CanN) puts("NO CYCLE");
	else puts("CYCLE");
	return 0;
}