// =====================================================================================
//
//       Filename:  1670.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 01:58:52
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
const int MOD = 987654321;

int Dy[11111], N;
int main() {
	cin >> N;
	Dy[0] = 1; Dy[2] = 1; Dy[4] = 2;
	for(int i=6; i<=N; i+=2)
		for(int j=1; j<=i-1; j+=2)
			Dy[i] = (1ll*Dy[i] + 1ll*Dy[j-1]*Dy[i-1-j]) % MOD;
	printf("%d\n", Dy[N]);
	return 0;
}










