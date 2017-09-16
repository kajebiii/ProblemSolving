// =====================================================================================
//
//       Filename:  5567.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 16:34:33
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

int N, M, Chk[555];
vector<int> V[555];
int main() {
	cin >> N >> M;
	for(int i=0, x, y; i<M; i++) 
	{
		scanf("%d%d", &x, &y);
		V[x].pb(y); V[y].pb(x);
	}
	queue<pi> Q; Q.push(mp(1, 0)); Chk[1] = 1;
	while(!Q.empty())
	{
		int now, dis; tie(now, dis) = Q.front(); Q.pop();
		if(dis == 2) continue;
		for(int nx : V[now])
			if(Chk[nx] == 0)
			{
				Chk[nx] = 1;
				Q.push(mp(nx, dis+1));
			}
	}
	int ans = 0; for(int i=1; i<=N; i++) if(Chk[i] == 1) ans++;
	cout << ans - 1;
	return 0;
}










