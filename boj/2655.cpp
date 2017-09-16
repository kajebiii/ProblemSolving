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

struct BLOCK
{
	int s, h, w, ix;
	const bool operator<(const BLOCK &o) const
	{
		if(w == o.w) return s > o.s;
		return w > o.w;
	}
}B[111];
int N, Dy[111], P[111];

vector<int> Ans;
void getIx(int ix)
{
	if(ix == 0) return;
	Ans.pb(B[ix].ix);
	getIx(P[ix]);
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;
	for(int i=0; i<N; i++)
		scanf("%d%d%d", &B[i].s, &B[i].h, &B[i].w),
		B[i].ix = i+1;
	B[N++] ={ INF, 0, INF, 0};
	sort(B, B+N);

	Dy[0] = 0;
	int ans = 0, ansIx  = -1;
	for(int i=1; i<N; i++)
	{
		for(int j=0; j<i; j++)
			if(B[j].s >= B[i].s)
			{
				Dy[i] = max(Dy[i], Dy[j] + B[i].h);
				if(Dy[i] == Dy[j] + B[i].h)
					P[i] = j;
			}
		ans = max(ans, Dy[i]);
		if(ans == Dy[i]) ansIx = i;
	}
	getIx(ansIx);
	cout << Ans.size();
	for(int x : Ans) printf("\n%d", x);
	return 0;
}