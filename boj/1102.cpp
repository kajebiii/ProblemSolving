// =====================================================================================
//
//       Filename:  1102.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 13:00:33
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
const int MAX_N = 16;

int N, P, Nr[MAX_N][MAX_N];
int Dis[1<<MAX_N];

int main() {
	cin >> N; for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> Nr[i][j];
	int state = 0;
	for(int i=0; i<N; i++) 
	{
		char x; cin >> x;
		if(x == 'Y') state += 1<<i;
	}
	cin >> P;

	queue<pi> Q;
	Q.push(mp(state, 0));

	for(int i=0; i<1<<N; i++) Dis[i] = INF;
	Dis[state] = 0;

	int ans = INF;
	while(!Q.empty())
	{
		pi now = Q.front(); Q.pop();
		if(Dis[now.fi] < now.se) continue;
		int cnt = 0; for(int i=0; i<N; i++) cnt += ( (now.fi & 1<<i) > 0);
		if(cnt >= P) ans = min(ans, now.se);
		for(int i=0; i<N; i++)
		{
			if( (now.fi & 1<<i) == 0) continue;
			for(int j=0; j<N; j++)
				if( (now.fi & 1<<j) == 0)
				{
					pi next = mp(now.fi | 1<<j, now.se + Nr[i][j]);
					if(Dis[next.fi] > next.se)
						Q.push(mp(next.fi, Dis[next.fi] = next.se));
				}
		}
	}
	if(ans == INF) ans = -1;
	cout << ans;
	return 0;
}










