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
const int MAX_N = 555;

int N, W[MAX_N], Nr[MAX_N][MAX_N];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &Nr[i][j]);
		for(int i=0; i<N; i++) scanf("%d", &W[i]);
		for(int i=0; i<N; i++)
		{
			int ix = -1;
			for(int j=0; j<N; j++) if(Nr[i][j] == 1) { ix = j; break; }
			for(int j=0; j<N; j++) swap(Nr[i][j], Nr[ix][j]);
		}

		bool isCan = true; int ans = 0;
		for(int i=0; i<N; i++)
		{
			if(W[i] < 0) { isCan = false; break; }
			int k = W[i];
			ans += k;
			for(int j=0; j<N; j++) W[j] -= Nr[i][j] * k;
		}
		if(isCan) printf("1 %d\n", ans);
		else printf("0\n");
	}
	return 0;
}