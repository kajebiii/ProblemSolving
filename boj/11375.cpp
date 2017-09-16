// =====================================================================================
//
//       Filename:  11375.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 13:17:30
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
const int MAX_N = 1e3 + 100;

int N, M, Match[MAX_N]; bool Visit[MAX_N];
vector<int> V[MAX_N];

bool find_match(int v)
{
	if(Visit[v] == true) return false;
	Visit[v] = true;
	for(int w : V[v])
		if(Match[w] == 0 || find_match(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}
int main() {
	cin >> N >> M;
	for(int i=1, n; i<=N; i++) 
	{
		scanf("%d", &n); 
		while(n--) {int x; scanf("%d", &x); V[i].pb(x);}
	}

	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++) Visit[j] = false;
		if(find_match(i))
			ans++;
	}
	cout << ans;
	return 0;
}










