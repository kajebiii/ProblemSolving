// =====================================================================================
//
//       Filename:  1328.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 11:51:26
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MOD = 1e9 + 7;

int C[101][101], Dy[101][101], F[101];
int get(int n, int k)
{
	if(n < k) return 0;
	if(k == 0 && n > 0) return 0;
	if(k == 0 && n == 0) return 1;
	if(Dy[n][k] != 0) return Dy[n][k] - 1;
	int r = 0;
	for(int i=1; i<=n; i++)
		r = (r + (1ll * get(i-1, k-1) * C[n-1][i-1]) % MOD * F[n-i] % MOD) % MOD;
	Dy[n][k] = r+1;
	return r;
}
int main() {
	int N, L, R; cin >> N >> L >> R;
	F[0] = 1; for(int i=1; i<=N; i++) F[i] = (1ll * F[i-1] * i) % MOD;
	for(int i=0, j; i<=N; i++) for(C[i][0]=1, j=1; j<=i; j++)
		C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	
	int ans = 0;
	for(int i=1; i<=N; i++)
		ans = (ans + (1ll * get(i-1, L-1) * get(N-i, R-1)) % MOD * C[N-1][i-1] % MOD) % MOD;
	cout << ans;
	return 0;
}











