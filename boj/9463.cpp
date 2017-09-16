// =====================================================================================
//
//       Filename:  9463.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 14:07:43
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
const int MAX_N = 1e5 + 1000;

int N, P, T[MAX_N*4], Idx[MAX_N];
void U(int v, int k) {T[v] = k; while(v/=2) T[v] = T[v*2] + T[v*2+1];}
int G(int a, int b) {return a<=b?G((a+1)/2, (b-1)/2)+(a%2?T[a]:0)+(b%2==0?T[b]:0):0;}
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d", &N);
		for(int i=0, x; i<N; i++) scanf("%d", &x), Idx[x] = i;
		for(P=1; P<N; P<<=1);
		for(int i=1; i<2*P; i++) T[i] = 0;
		ll ans = 0;
		for(int i=0, x; i<N; i++)
		{
			scanf("%d", &x);
			ans += 1ll* G(P+Idx[x], P+N-1);
			U(P+Idx[x], 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}










