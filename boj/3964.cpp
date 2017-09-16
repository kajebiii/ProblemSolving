// =====================================================================================
//
//       Filename:  3964.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/24/2016 02:56:31
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

ll N, K, minV;
void Check(ll i)
{
	ll cnt = 0;
	while(K % i == 0)
	{
		cnt++;
		K /= i;
	}
	ll how = 0, nowN = N;
	do{how += nowN / i;}while(nowN /= i);
	minV = min(minV, how / cnt);
}
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%lld%lld", &N, &K);
		minV = 1ll * INF * INF;
		for(ll i=2; i*i<=K; i++)
		{
			if(K % i != 0) continue;
			Check(i);
		}
		if(K != 1) Check(K);
		printf("%lld\n", minV);
	}
	return 0;
}










