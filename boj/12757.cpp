// =====================================================================================
//
//       Filename:  12757.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 15:45:18
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

int N, M, K;
map<int, ll> Map;
int main() {
	cin >> N >> M >> K;
	for(int i=0, x, y; i<N; i++) scanf("%d%d", &x, &y), Map[x] = 1ll*y;
	for(int i=0; i<M; i++)
	{
		int t, k, v; scanf("%d%d", &t, &k);
		auto itUp = Map.lower_bound(k), itLo = itUp; 
		if(itLo != Map.begin()) itLo--;
		ll upV = (itUp != Map.end()) ? itUp -> fi:INF;
		ll loV = (itUp != Map.begin()) ? itLo -> fi:-INF;
		ll diffU = abs(upV - k), diffL = abs(loV - k);
		ll minV = min(diffU, diffL);
		if(t == 1)
		{
			scanf("%d", &v);
			Map[k] = 1ll * v;
		}
		else if(t == 2)
		{
			scanf("%d", &v);
			if(minV > K) continue;
			if(diffU == diffL) continue;
			if(diffU < diffL) itUp -> se = v;
			else itLo -> se = v;
		}
		else if(t == 3)
		{

			if(minV > K) {puts("-1"); continue;}
			if(diffU == diffL) {puts("?"); continue;}
			if(diffU < diffL) printf("%lld\n", itUp -> se);
			else printf("%lld\n", itLo -> se);
		}
		
	}
	return 0;
}










