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

int N, Dy[1111111], Now[22];
vector<int> V;
int getDy(int k)
{
	if(Dy[k] != -1) return Dy[k];
	bool canMake = true;
	int temp = k;
	do { if(Now[temp % 10] == 0) { canMake = false; break; } } while(temp /= 10);
	if(canMake) { V.pb(k); return Dy[k] = 0; }

	int result = INF;
	for(int i=2; i*i<=k; i++)
	{
		if(k % i != 0) continue;
		int a = getDy(i), b = getDy(k/i);
		if(a == INF || b == INF) continue;
		result = min(result, a + b + 1);
	}
	V.pb(k); return Dy[k] = result;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	int TC; cin >> TC;
	for(int i=0; i<=1000000; i++) Dy[i] = -1;
	while(TC--)
	{
		scanf("%d", &N); 
		V.clear();
		for(int i=0; i<10; i++) Now[i] = 0;
		for(int i=0, x; i<N; i++) scanf("%d", &x), Now[x] = 1;
		int M; scanf("%d", &M);
		for(int i=0, x; i<M; i++)
			scanf("%d", &x), printf("%d\n", getDy(x)==INF?-1:getDy(x));
		for(int x : V) Dy[x] = -1;
	}
	return 0;
}