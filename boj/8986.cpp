// =====================================================================================
//
//       Filename:  8986.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 14:00:45
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 1e5 + 100;

int N, Nr[MAX_N];

ll getCnt(ll m)
{
	ll r = 0;
	for(int i=0; i<N; i++)
		r += 1ll * abs(Nr[i] - m*i);
	return r;
}

int main() {	
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	
	ll l = 0, r = 1000000000;
	while(l < r)
	{
		ll m0 = (l + r) / 2, m1 = m0 + 1;
		ll m0Cnt = getCnt(m0), m1Cnt = getCnt(m1);
		if(m0Cnt <= m1Cnt) r = m0;
		else l = m1;
	}
	cout << getCnt(l);
	return 0;
}










