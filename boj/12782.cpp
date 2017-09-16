// =====================================================================================
//
//       Filename:  12782.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 22:08:59
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
const int MAX_N = 1e6 + 1000;

char A[MAX_N], B[MAX_N];
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%s%s", A, B);
		int cnt[2] = {0, 0}, N = (int)strlen(A);
		for(int i=0; i<N; i++)
			if(A[i] != B[i]) cnt[B[i] - '0']++;
		int minV = min(cnt[0], cnt[1]);
		printf("%d\n", minV + cnt[0] + cnt[1] - minV - minV);
	}
	return 0;
}










