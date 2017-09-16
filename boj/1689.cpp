// =====================================================================================
//
//       Filename:  1689.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/24/2016 15:52:20
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

int N; int Xs[1001001], Ys[1001001];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d%d", &Xs[i], &Ys[i]);
	sort(Xs, Xs+N); sort(Ys, Ys+N);
	int cnt = 0, ans = 0, ix = 0;
	for(int i=0; i<N; i++)
	{
		int now = Xs[i]; cnt++;
		while(ix < N && Ys[ix] <= now) ix++, cnt--;
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}










