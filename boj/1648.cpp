// =====================================================================================
//
//       Filename:  1648.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 14:25:47
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
const int MAX_N = 14;
const int MOD = 9901;

int Dy[1<<MAX_N][MAX_N][MAX_N], N, M;

int getCnt(int state, int n, int m)
{
	if(Dy[state][n][m] != 0) return Dy[state][n][m] - 1;
	if(n == N) return state == 0 ? 1 : 0;
	if(m == M) return getCnt(state, n+1, 0);
	if(state & 1<<m) return getCnt(state - (1<<m), n, m+1);

	int result = 0;
	if( (state & 1<<m+1) == 0 && m+1 < M)
		result += getCnt(state, n, m+2);
	result += getCnt(state + (1<<m), n, m+1);
	result %= MOD;
	Dy[state][n][m] = result + 1;
	return result;
}

int main() {
	cin >> N >> M;
	printf("%d", getCnt(0, 0, 0));
	return 0;
}










