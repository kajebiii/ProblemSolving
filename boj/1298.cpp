// =====================================================================================
//
//       Filename:  1298.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 16:33:13
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

int N, M, Match[111], Visit[111];
vector<int> V[111];
bool findMatch(int v)
{
	if(Visit[v] == 1) return false;
	Visit[v] = 1;
	for(int w : V[v])
		if(Match[w] == 0 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}
int main() {
	cin >> N >> M;
	while(M--) {int x, y; scanf("%d%d", &x, &y); V[x].pb(y);}
	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++) Visit[j] = 0;
		if(findMatch(i)) ans++;
	}
	cout << ans;
	return 0;
}









