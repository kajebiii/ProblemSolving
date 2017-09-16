// =====================================================================================
//
//       Filename:  3758.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 13:08:38
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

struct DATA
{
	int score, how, time, team;
	DATA()
	{
		score = how = time = team = 0;
	}
	const bool operator<(const DATA &o) const
	{
		if(score != o.score) return score > o.score;
		if(how != o.how) return how < o.how;
		return time < o.time;
	}
}D[111];
int S[111][111];

int main() {
	int T; cin >> T;
	while(T--)
	{
		int N, K, T, M;
		scanf("%d%d%d%d", &N, &K, &T, &M);
		for(int i=0; i<M; i++)
		{
			int n, k, s;
			scanf("%d%d%d", &n, &k, &s);
			S[n][k] = max(S[n][k], s);
			D[n].time = i;
			D[n].how = D[n].how + 1;
			D[n].team = n;
		}
		for(int i=1; i<=N; i++) 
		{
			int sum = 0;
			for(int j=1; j<=K; j++) sum += S[i][j];
			D[i].score = sum;
		}
		sort(D+1, D+N+1);
		for(int i=1; i<=N; i++)
			if(D[i].team == T)
				printf("%d\n", i);

		for(int i=1; i<=N; i++) for(int j=1; j<=K; j++) S[i][j] = 0;
		for(int i=1; i<=N; i++) D[i] = DATA();
	}
	return 0;
}










