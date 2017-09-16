// =====================================================================================
//
//       Filename:  3079.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 14:41:33
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 1e5 + 200;

int N, M, Nr[MAX_N];
int main()
{
	cin >> N >> M; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	ll s = 0, e = 1ll * INF * INF / 4;
	while(s < e)
	{
		ll m = (s + e + 0) / 2;
		ll now = 0;
		for(int i=0; i<N; i++) 
		{
			now += m / Nr[i];
			if(now >= M) break;
		}
		if(now >= M)
			e = m;
		else
			s = m+1;
	}
	cout << e;
	return 0;
}










