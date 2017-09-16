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
const int MOD = 1e6 + 7;
const int MAX_N = 222;

int N, M, A, B, C[MAX_N * 2][MAX_N * 2];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> M >> A >> B;
	for(int i=0, j; i<=N+M; i++) for(C[i][0] = 1, j=1; j<=i; j++)
		C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	printf("%lld\n", 1ll * C[A-1+B-1][A-1] * C[N-A+M-B][N-A] % MOD);
	return 0;
}