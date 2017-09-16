// =====================================================================================
//
//       Filename:  1788.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 01:54:25
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
const int MOD = 1e9;

int F[1111111], N;
int main() {
	F[1] = 1; cin >> N; for(int i=2; i<=abs(N); i++) F[i] = (F[i-1]+F[i-2])%MOD;
	if(N == 0) printf("0\n0");
	else if(N < 0 && abs(N)%2 == 0) printf("-1\n%d", F[abs(N)]);
	else printf("1\n%d", F[abs(N)]);
	return 0;
}










