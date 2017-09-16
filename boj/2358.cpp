// =====================================================================================
//
//       Filename:  2358.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 22:33:09
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

int N; pi P[101101];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d%d", &P[i].fi, &P[i].se);
	int ans = 0;
	for(int k=0; k<2; k++)
	{
		sort(P, P+N);
		for(int i=0; i<N-1; i++)
			if(P[i].fi == P[i+1].fi && (i == 0 || P[i-1].fi != P[i].fi))
				ans++;
		for(int i=0; i<N; i++) swap(P[i].fi, P[i].se);
	}
	cout << ans;
	return 0;
}










