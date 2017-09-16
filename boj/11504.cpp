// =====================================================================================
//
//       Filename:  11504.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 17:44:22
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

int N, M, Nr[222];
ll X, Y;
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d%d", &N, &M);
		X = Y = 0;
		for(int i=0, k; i<M; i++) scanf("%d", &k), X *= 10, X += k;
		for(int i=0, k; i<M; i++) scanf("%d", &k), Y *= 10, Y += k;
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]), Nr[N+i] = Nr[i];
		int ans = 0;
		for(int i=0; i<N; i++)
		{
			ll now = 0;
			for(int j=0; j<M; j++) now *= 10, now += Nr[i+j];
			if(now >= X && now <= Y) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}










