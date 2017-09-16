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

struct NODE
{
	char c;
	int v;
	const bool operator<(const NODE &o) const
	{
		if(c != o.c) return c < o.c;
		return v < o.v;
	}
}C[5];
int Cnt[10];
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	for(int i=0; i<5; i++) scanf("%c%d\n", &C[i].c, &C[i].v);

	int maxV = 0;
	for(int i=0; i<5; i++)
	{
		maxV = max(maxV, C[i].v);
		Cnt[C[i].v]++;
	}
	sort(C, C+5);

	int ans = 0;
	if(C[0].c == C[4].c && C[0].v + 4 == C[4].v) ans = max(ans, 900 + C[4].v);
	for(int i=1; i<=9; i++) if(Cnt[i] >= 4) ans = max(ans, 800 + i);
	for(int i=1; i<=9; i++) for(int j=1; j<=9; j++)
		if(Cnt[i] >= 3 && Cnt[j] >= 2 && i != j) ans = max(ans, 700 + i * 10 + j);
	if(C[0].c == C[4].c) ans = max(ans, 600 + maxV);
	for(int i=5; i<=9; i++)
	{
		bool flag = true;
		for(int j=i-4; j<=i; j++) if(Cnt[j] != 1) flag = false;
		if(flag) ans = max(ans, 500 + i);
	}
	for(int i=1; i<=9; i++) if(Cnt[i] >= 3) ans = max(ans, 400 + i);
	for(int i=1; i<=9; i++) for(int j=1; j<=9; j++)
		if(Cnt[i] >= 2 && Cnt[j] >= 2 && i != j)
			ans = max(ans, 300 + max(i, j) * 10 + min(i, j));
	for(int i=1; i<=9; i++) if(Cnt[i] >= 2)
		ans = max(ans, 200 + i);
	ans = max(ans, 100 + maxV);

	printf("%d", ans);
	return 0;
}