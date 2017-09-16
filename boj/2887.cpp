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

const int MAX_N = 1e5 + 100;

int N;
int UNF[MAX_N];
int F(int v) { return UNF[v] == v ? v : UNF[v] = F(UNF[v]); }
void U(int a, int b) { UNF[F(a)] = F(b); }

vector<pi> Ax[3];
vector<tuple<int, int, int> > V;
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	
	scanf("%d", &N);
	for(int i=0; i<N; i++) UNF[i] = i;
	for(int i=0, x; i<N; i++)
		for(int j=0; j<3; j++)
		{
			int x; scanf("%d", &x);
			Ax[j].pb(mp(x, i));
		}
	for(int j=0; j<3; j++)
	{
		sort(Ax[j].begin(), Ax[j].end());
		for(int i=1; i<N; i++)
			V.pb(make_tuple(Ax[j][i].fi - Ax[j][i-1].fi, Ax[j][i-1].se, Ax[j][i].se));
	}
	sort(V.begin(), V.end());

	ll ans = 0;
	for(auto &temp : V)
	{
		int l, x, y;
		tie(l, x, y) = temp;
		if(F(x) != F(y))
		{
			ans += 1ll * l;
			U(x, y);
		}
	}
	cout << ans;
	return 0;
}