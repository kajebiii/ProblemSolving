// =====================================================================================
//
//       Filename:  1167.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 16:59:20
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

int N, Dis[MAX_N];
vector<pi> V[MAX_N];
int findMax(int v, int p)
{
	if(p == -1) Dis[v] = 0;
	
	int maxIx = v, maxDis = 0;
	for(pi temp : V[v])
	{
		int w = temp.fi, c = temp.se;
		if(w == p) continue;
		Dis[w] = Dis[v] + c;
		int now = findMax(w, v);
		if(Dis[now] > maxDis)
		{
			maxDis = Dis[now];
			maxIx = now;
		}
	}
	return maxIx;
}
int main() {
	cin >> N;
	for(int i=1; i<=N; i++)
	{
		int now; scanf("%d", &now);
		while(1)
		{
			int x, y; scanf("%d", &x);
			if(x == -1) break;
			scanf("%d", &y);
			V[now].pb(mp(x, y));
		}
	}
	int A = findMax(1, -1);
	int B = findMax(A, -1);
	cout << Dis[B];
	return 0;
}










