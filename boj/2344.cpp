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

const int MAX_N = 1e3 + 100;

int N, M, Nr[MAX_N][MAX_N];

bool isIn(pi x) { return !(x.fi <= 0 || x.se <= 0 || x.fi > N || x.se > M); }
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		scanf("%d", &Nr[i][j]), Nr[i][j] *= -1;

	int cnt = 0;
	vector<pi> V;
	for(int i=1; i<=N; i++) V.pb(mp(i, 0));
	for(int i=1; i<=M; i++) V.pb(mp(N+1, i));
	for(int i=N; i>=1; i--) V.pb(mp(i, M+1));
	for(int i=M; i>=1; i--) V.pb(mp(0, i));

	for(pi &temp : V) Nr[temp.fi][temp.se] = ++cnt;

	for(pi &temp : V)
	{
		pi now; int direc = -1;
		for(int k=0; k<4; k++)
		{
			pi n = temp + Ch[k];
			if(!isIn(n)) continue;
			now = n;
			direc = k;
		}
		while(isIn(now))
		{
			if(Nr[now.fi][now.se] == -1) direc = 3 - direc;
			now = now + Ch[direc];
		}
		printf("%d ", Nr[now.fi][now.se]);
	}

	return 0;
}