// =====================================================================================
//
//       Filename:  8983.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 03:19:05
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
const int MAX_N = 1e5 + 100, MAX_M = 1e5 + 100;

int M, N, L, X[MAX_M];
int main() {
	cin >> M >> N >> L; for(int i=0; i<M; i++) scanf("%d", &X[i]);
	sort(X, X+M); 
	int ans = 0;
	for(int i=0; i<N; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		int r = (int)(upper_bound(X, X+M, x) - X), l = r - 1;
		int nowMin = INF;
		if(r < M)  nowMin = min(nowMin, abs(X[r]-x) + y);
		if(l >= 0) nowMin = min(nowMin, abs(X[l]-x) + y);
		if(nowMin <= L) ans++;
	}
	cout << ans;
	return 0;
}










