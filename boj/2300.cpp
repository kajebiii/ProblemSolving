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

struct POINT
{
	int x, y;
	const bool operator<(const POINT &o) const
	{
		return x < o.x;
	}
}P[10101];
int N, Dy[10101];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;
	for(int i=1; i<=N; i++) scanf("%d%d", &P[i].x, &P[i].y);
	sort(P+1, P+N+1);

	cin >> N;
	for(int i=1; i<=N; i++)
	{
		int now = 0;
		Dy[i] = INF;
		for(int j=i; j>=1; j--)
		{
			now = max(now, abs(P[j].y) * 2);
			now = max(now, P[i].x - P[j].x);
			Dy[i] = min(Dy[i], Dy[j-1] + now);
		}
	}
	cout << Dy[N];
	return 0;
}