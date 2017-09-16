// =====================================================================================
//
//       Filename:  1531.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 13:24:10
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

int N, M, Cnt[111][111];
int main() {
	cin >> N >> M;
	for(int k=0; k<N; k++)
	{
		int x[2], y[2]; for(int i=0; i<2; i++) scanf("%d%d", &x[i], &y[i]);
		for(int i=x[0]; i<=x[1]; i++) for(int j=y[0]; j<=y[1]; j++)
			Cnt[i][j]++;
	}
	int ans = 0;
	for(int i=1; i<=100; i++) for(int j=1; j<=100; j++)
		if(Cnt[i][j] > M) ans++;
	cout << ans;
	return 0;
}










