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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

const int MAX_N = 1e3 + 100;

int N, K;
pi P[MAX_N];
bool Chk[MAX_N];

double dis(int i, int j)
{
	int dx = P[i].fi - P[j].fi, dy = P[i].se - P[j].se;
	return sqrt(dx * dx + dy * dy);
}
int main() 
{
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> K;
	P[1] = mp(0, 0); P[N+2] = mp(10000, 10000);
	for(int i=2; i<=N+1; i++) scanf("%d%d", &P[i].fi, &P[i].se);
	N += 2;

	int result;
	for(int l=0, r=22222; l<r; )
	{
		int m = (l + r) >> 1;
		queue<pi> Q;
		Q.push(mp(1, 0));
		for(int i=1; i<=N; i++) Chk[i] = false;
		while(!Q.empty())
		{
			int now, how; tie(now, how) = Q.front(); Q.pop();
			if(how == K+1) continue;
			for(int i=1; i<=N; i++)
			{
				if(Chk[i] == true) continue;
				if(dis(now, i) > 10 * m) continue;
				Chk[i] = true;
				Q.push(mp(i, how+1));
			}
		}
		if(Chk[N] == true) r = m;
		else l = m + 1;
		result = r;
	}
	cout << result;
	return 0;
}