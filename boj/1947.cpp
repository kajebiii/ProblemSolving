// =====================================================================================
//
//       Filename:  1947.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 02:52:20
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

ll Dy[1001001];
int main() {
	int N; cin >> N;
	Dy[1] = 0;
	Dy[2] = 1;
	for(int i=3; i<=N; i++)
		Dy[i] = 1ll * (i-1) * (Dy[i-2] + Dy[i-1]) % MOD;

	cout << Dy[N];
	return 0;
}










