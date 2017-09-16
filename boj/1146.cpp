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

const int MAX_N = 1e2 + 10, MOD = 1e6;

int N;
int C[MAX_N][MAX_N], Dy[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	
	cin >> N;
	if(N == 1) { puts("1"); return 0; }
	for(int i=0, j=0; i<=N; i++) for(C[i][0] = 1, j=1; j<=i; j++)
		C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;

	Dy[0] = 1;
	Dy[1] = 1;
	for(int i=2; i<=N; i++)
		for(int j=2; j<=i; j+=2)
			Dy[i] += (1ll * C[i-1][j-1] * Dy[j-1] % MOD * Dy[i-j] % MOD);
	cout << (Dy[N] * 2) % MOD;
	return 0;
}