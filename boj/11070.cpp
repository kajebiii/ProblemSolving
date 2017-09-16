// =====================================================================================
//
//       Filename:  11070.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 14:21:01
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

int N, M;
int Get[1111][2];
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++) Get[i][0] = Get[i][1] = 0;
		for(int i=0; i<M; i++)
		{
			int a, aa, b, bb; scanf("%d%d%d%d", &a, &b, &aa, &bb);
			Get[a][0] += aa; Get[b][1] += aa;
			Get[b][0] += bb; Get[a][1] += bb;
		}
		int maxV = -1, minV = INF;
		for(int i=1; i<=N; i++)
		{
			int now = -1;
			if(Get[i][0] == Get[i][1] && Get[i][0] == 0) now = 0;
			else now = 1000ll * Get[i][0] * Get[i][0] / (Get[i][0] * Get[i][0] + Get[i][1] * Get[i][1]);
			maxV = max(maxV, now);
			minV = min(minV, now);
		}
		printf("%d\n%d\n", maxV, minV);
	}
	return 0;
}










