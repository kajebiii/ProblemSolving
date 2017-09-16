// =====================================================================================
//
//       Filename:  10422.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 09:40:09
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
#include <assert.h>

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

int Dy[5555];
int main() {
	int TC; cin >> TC;
	Dy[0] = Dy[2] = 1;
	for(int i=4; i<=5000; i+=2)
		for(int j=0; j<=i-2; j+=2)
			Dy[i] = (1ll * Dy[i] + 1ll * Dy[j] * Dy[i-2-j]) % MOD;
	while(TC--)
	{
		int N; cin >> N;
		printf("%d\n", Dy[N]);
	}
	return 0;
}










