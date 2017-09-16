// =====================================================================================
//
//       Filename:  1564.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 20:59:02
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
const int MOD = 100000;

int pow(int a, int b)
{
	int r = 1, p = a;
	while(b)
	{
		if(b%2) r = 1ll * r * p % MOD;
		p = 1ll * p * p % MOD;	   
		b /= 2;
	}
	return r;
}
int main() {
	int N, two = 0, ans = 1; cin >> N;
	for(int i=1; i<=N; i++)
	{
		int now = i;
		while(now % 2 == 0) two++, now /= 2;
		while(now % 5 == 0) two--, now /= 5;
		ans = 1ll * ans * now % MOD;
	}
	ans = 1ll * ans * pow(2, two) % MOD;
	cout << ans;
	return 0;
}










