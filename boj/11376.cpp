// =====================================================================================
//
//       Filename:  11376.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 16:37:39
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
const int MAX_N = 1e3 + 100;

int Visit[MAX_N*2], Match[MAX_N], N, M;
vector<int> V[MAX_N*2];

bool findMatch(int v)
{
	if(Visit[v] == 1) return false;
	Visit[v] = 1;
	for(int w : V[v])
		if(Match[w] == -1 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}
int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++)
	{
		int k; scanf("%d", &k);
		for(int j=0, x; j<k; j++)
		{
			scanf("%d", &x);
			V[i*2].pb(x);
			V[i*2+1].pb(x);
		}
	}

	int ans = 0;
	for(int i=1; i<=M; i++) Match[i] = -1;
	for(int i=0; i<2*N; i++)
	{
		for(int j=0; j<2*N; j++) Visit[j] = 0;
		if(findMatch(i)) ans++;
	}
	cout << ans;
	return 0;
}










