// =====================================================================================
//
//       Filename:  2482.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 18:51:02
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MOD = 1e9 + 3;

int N, K, Dy[1111][1111][2];
int get(int n, int k, int p)
{
	if(k < 0) return 0;
	if(Dy[n][k][p] != 0) return Dy[n][k][p] - 1;
	if(n >= N && k > 0) return 0;
	if(n == N+1) return 1-p;
	if(n == N) return 1;
	int r = get(n+2, k-1, p) + get(n+1, k, p);
	r %= MOD;

	Dy[n][k][p] = r + 1;
	return r;
}
int main() {
	cin >> N >> K;
	cout << (get(1, K, 0) + get(2, K-1, 1)) % MOD;
	return 0;
}










