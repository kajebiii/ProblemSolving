// =====================================================================================
//
//       Filename:  1392.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 16:15:22
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

int N, Q, A[111];
int main() {
	cin >> N >> Q;
	int sum = -1; for(int i=0, x; i<N; i++) scanf("%d", &x), A[i] = (sum = sum + x);
	for(int i=0, x; i<Q; i++)
	{
		scanf("%d", &x);
		int ix = (int)(lower_bound(A, A+N, x) - A);
		if(debug) printf(">>");
		printf("%d\n", ix+1);
	}
	return 0;
}










