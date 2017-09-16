#include <stdio.h>
#include <functional>
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

const int MAX_N = 1e3 + 10, MAX_M = 1e3 + 10;

int N, M;
int isMatch[MAX_M], isOther[MAX_N], Visited[MAX_N];
bool Chk[MAX_N];
vector<int> V[MAX_N];

bool findMatch(int v, bool o)
{
	if(Visited[v] == 1) return false;
	Visited[v] = 1;
	Chk[v] = o;

	for(int w : V[v])
		if(isMatch[w] == 0 || findMatch(isMatch[w], o) == true)
		{
			isMatch[w] = v;
			isOther[v] = w;
			return true;
		}
	return false;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		int k; scanf("%d", &k);
		for(int j=0, x; j<k; j++) scanf("%d", &x), V[i].pb(x);
	}

	int cnt = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++) Visited[j] = 0;
		if(findMatch(i, false) == true)
			cnt++;
	}
	printf("%d\n", cnt);
	for(int i=1; i<=N; i++)
	{
		if(isOther[i] != 0) continue;
		for(int j=1; j<=N; j++) Visited[j] = 0;
		findMatch(i, true);
	}
	
	vector<int> Ans[2];
	for(int i=1; i<=N; i++)
	{
		if(Chk[i] == false) Ans[0].pb(i);
		else if(isOther[i] != 0) Ans[1].pb(isOther[i]);
	}
	for(int k=0; k<2; k++)
	{
		printf("%d", (int)Ans[k].size());
		for(int x : Ans[k]) printf(" %d", x);
		puts("");
	}
	return 0;
}