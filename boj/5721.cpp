// =====================================================================================
//
//       Filename:  5721.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 18:07:25
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
const int MAX_N = 1e5 + 100;

int N, M;
int Row[MAX_N], Col[MAX_N];
int main() {
	while(1)
	{
		scanf("%d%d", &N, &M); if(N+M==0) break;
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=M; j++) scanf("%d", &Row[j]);
			Col[i] = Row[1];
			for(int j=2; j<=M; j++) 
				Col[i] = max(Col[i], Row[j] = max(Row[j-1], Row[j-2] + Row[j]));
		}
		int ans = Col[1];
		for(int i=2; i<=N; i++)
			ans = max(ans, Col[i] = max(Col[i-1], Col[i-2] + Col[i]));
		printf("%d\n", ans);
	}
	return 0;
}










