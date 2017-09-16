// =====================================================================================
//
//       Filename:  1516.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 03:37:49
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

int N, Cnt[555], Dis[555], Nr[555];
vector<int> V[555];
int main() {
	cin >> N;
	for(int i=1; i<=N; i++)
	{
		scanf("%d", &Nr[i]);
		while(1)
		{
			int x; scanf("%d", &x);
			if(x == -1) break;
			V[x].pb(i);
			Cnt[i]++;
		}
	}
	queue<int> Q; for(int i=1; i<=N; i++) if(Cnt[i] == 0) Q.push(i);
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		Dis[now] += Nr[now];
		for(int next : V[now])
		{
			Dis[next] = max(Dis[next], Dis[now]);
			if(--Cnt[next] == 0) Q.push(next);
		}
	}
	for(int i=1; i<=N; i++) printf("%d\n", Dis[i]);
	return 0;
}










