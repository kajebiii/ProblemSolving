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

int N, M, Sol[22][22], Chk[22];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int k; scanf("%d", &k);
		for(int l=0, x; l<k; l++) scanf("%d", &x), Sol[i][x] = 1;
	}

	int ans = INF;
	for(int p=0; p<(1<<M); p++)
	{
		for(int i=1; i<=N; i++) Chk[i] = 0;
		int cnt = 0;
		for(int i=0; i<M; i++) if(p & 1<<i)
		{
			cnt++;
			for(int j=1; j<=N; j++) Chk[j] |= Sol[i][j];
		}
		int sum = accumulate(Chk + 1, Chk + 1 + N, 0);
		if(sum == N) ans = min(ans, cnt);
	}
	if(ans == INF) ans = -1;
	printf("%d\n", ans);
	return 0;
}