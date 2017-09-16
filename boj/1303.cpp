// =====================================================================================
//
//       Filename:  1303.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/26/2016 10:17:49
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

int N, M;
map<char, int> Cnt;
char Map[111][111];
bool Chk[111][111];
int main() {
	cin >> M >> N;
	for(int i=1; i<=N; i++) scanf("%s", Map[i]+1);
	for(int i=1; i<=N; i++) Map[i][0] = Map[i][M+1] = 'C';
	for(int i=1; i<=M; i++) Map[0][i] = Map[N+1][i] = 'C';
	Cnt['W'] = Cnt['B'] = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		if(Chk[i][j] == true) continue;
		queue<pi> Q;
		int cnt = 0;
		Q.push(mp(i, j)); Chk[i][j] = true;
		while(!Q.empty())
		{
			int x, y; tie(x, y) = Q.front(); Q.pop(); cnt++;
			for(int k=0; k<4; k++)
			{
				int nx = x + Ch[k].fi, ny = y + Ch[k].se;
				if(Map[nx][ny] != Map[x][y]) continue;
				if(Chk[nx][ny] == true) continue;
				Chk[nx][ny] = true;
				Q.push(mp(nx, ny));
			}
		}
		Cnt[Map[i][j]] += cnt * cnt;
	}
	printf("%d %d\n", Cnt['W'], Cnt['B']);
	return 0;
}










