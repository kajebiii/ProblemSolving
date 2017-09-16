// =====================================================================================
//
//       Filename:  10881.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 22:04:53
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

pi R[3], A[3];
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		for(int i=0; i<3; i++) scanf("%d%d", &R[i].fi, &R[i].se);
		int C[3] = {0, 1, 2};
		int ans = INF;
		do
		{
			for(int l=0; l<8; l++)
			{
				for(int i=0; i<3; i++)
					A[i] = R[C[i]];
				for(int i=0; i<3; i++) if(l & (1<<i))
					swap(A[i].fi, A[i].se);
				ans = min(ans, (A[0].fi+A[1].fi+A[2].fi) * (max(A[0].se, max(A[1].se, A[2].se))) );
				ans = min(ans, (A[0].se+A[1].se+A[2].se) * (max(A[0].fi, max(A[1].fi, A[2].fi))) );
				ans = min(ans, (max(A[0].fi, A[1].fi) + A[2].fi) * (max(A[0].se + A[1].se, A[2].se)));
				ans = min(ans, (max(A[0].fi, A[2].fi) + A[1].fi) * (max(A[0].se + A[2].se, A[1].se)));
			}
		}while(next_permutation(C, C+3));
		printf("%d\n", ans);
	}
	return 0;
}










