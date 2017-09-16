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

map<int, int> M;
map<int, int> F;
int N, C;
struct NR
{
	int x, ix, cnt;
	const bool operator<(const NR &o) const
	{
		if(cnt == o.cnt) return ix < o.ix;
		return cnt > o.cnt;
	}
}Nr[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> C;
	for(int i=0; i<N; i++)
	{
		scanf("%d", &Nr[i].x);
		if(M.count(Nr[i].x) == 0) M[Nr[i].x] = 1, F[Nr[i].x] = i;
		else M[Nr[i].x]++;
	}
	for(int i=0; i<N; i++)
		Nr[i].cnt = M[Nr[i].x];
	for(int i=0; i<N; i++)
		Nr[i].ix = F[Nr[i].x];

	sort(Nr, Nr+N);
	for(int i=0; i<N; i++)
		printf("%d ", Nr[i].x);
	return 0;
}