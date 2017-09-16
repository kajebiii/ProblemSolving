// =====================================================================================
//
//       Filename:  2643.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 15:40:41
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
const int MAX_N = 111;

int N, Cnt[MAX_N];
struct RECT
{
	int x, y, ix;
	const bool operator<(const RECT &o) const
	{
		if(x == o.x && y == o.y) return ix < o.ix;
		if(x == o.y && y == o.x) return ix < o.ix;
		if(x <= o.x && y <= o.y) return true;
		if(x <= o.y && y <= o.x) return true;
		return false;
	}
}R[MAX_N];
vector<int> V[MAX_N];
int Dis[MAX_N];

int main() {
	int N; cin >> N; 
	for(int i=0; i<N; i++) 
		scanf("%d%d", &R[i].x, &R[i].y),
		R[i].ix = i;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++)
	{
		if(i == j) continue;
		if(R[i] < R[j]) V[i].pb(j), Cnt[j]++;
	}

	queue<int> Q;
	for(int i=0; i<N; i++) if(Cnt[i] == 0) Q.push(i), Dis[i] = 1;
	
	int ans = 0;
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		ans = max(ans, Dis[now]);
		for(int next : V[now])
		{
			Dis[next] = max(Dis[next], Dis[now] + 1);
			Cnt[next]--;
			if(Cnt[next]) continue;
			Q.push(next);
		}
	}
	cout << ans;
	return 0;
}










