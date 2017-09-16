// =====================================================================================
//
//       Filename:  7795.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 03:58:15
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

int Ns[22222], Ms[22222];
int main() {
	int T; cin >> T;
	while(T--)
	{
		int N, M; scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++) scanf("%d", &Ns[i]);
		for(int i=0; i<M; i++) scanf("%d", &Ms[i]); sort(Ms, Ms+M);
		int ans = 0;
		for(int i=0; i<N; i++)
			ans += (int)(lower_bound(Ms, Ms+M, Ns[i]) - Ms);
		printf("%d\n", ans);
	}
	return 0;
}










