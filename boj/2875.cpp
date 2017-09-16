// =====================================================================================
//
//       Filename:  2875.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 17:24:31
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

int main() {
	int N, M, K; cin >> N >> M >> K;
	K -= N%2;
	N /= 2;
	int maxV = min(N, M);
	if(N > maxV) K -= (N-maxV)*2, N = maxV;
	if(M > maxV) K -= (M-maxV)*1, M = maxV;
	if(K < 0) K = 0;
	cout << maxV - (K+2) / 3;
	return 0;
}










