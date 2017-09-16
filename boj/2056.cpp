// =====================================================================================
//
//       Filename:  2056.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 22:03:21
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
const int MAX_N = 10101;

int Cnt[MAX_N], Nr[MAX_N], Val[MAX_N];
vector<int> V[MAX_N];
int main() {
	int N; cin >> N;
	for(int i=1; i<=N; i++)
	{
		scanf("%d", &Nr[i]);
		int k; scanf("%d", &k); Cnt[i] = k;
		while(k--) {int x; scanf("%d", &x); V[x].pb(i);}
	}
	queue<int> Q; for(int i=1; i<=N; i++) if(Cnt[i] == 0) Q.push(i);
	
	int ans = 0;
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		Val[now] += Nr[now];
		ans = max(Val[now], ans);

		for(int next : V[now])
		{
			Val[next] = max(Val[next], Val[now]);
			if(--Cnt[next] == 0) Q.push(next);
		}
	}
	cout << ans;
	return 0;
}










