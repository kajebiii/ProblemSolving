// =====================================================================================
//
//       Filename:  11401.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/30/2016 15:02:28
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
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const ll MOD = 10007;

ll N, K;
ll p(ll a, ll b, ll m) {return b?b%2?p(a,b^1,m)*a%m:p(a*a%m,b>>1,m):1;}
ll F[4004000];

int main() {
	cin >> N >> K;
	F[0] = 1; for(int i=1; i<=N; i++) F[i] = F[i-1] * i % MOD;
	printf("%lld", F[N]*p(F[N-K], MOD-2, MOD)%MOD*p(F[K], MOD-2, MOD)%MOD);
	return 0;
}










