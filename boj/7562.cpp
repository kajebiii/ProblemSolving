// =====================================================================================
//
//       Filename:  7562.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:25:14
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
const int CY[8] = {-1, +1, -2, +2, -2, +2, -1, +1};

int Dis[333][333];
int main() {
	int T; cin >> T;
	while(T--)
	{
		int L, A, B, C, D;
		cin >> L >> A >> B >> C >> D;
		for(int i=0; i<L; i++) for(int j=0; j<L; j++)
			Dis[i][j] = -1;
		queue<pi> Q;
		Q.push(mp(A, B));
		Dis[A][B] = 0;
		while(!Q.empty())
		{
			pi now = Q.front(); Q.pop();
			if(now.fi == C && now.se == D)
			{
				printf("%d\n", Dis[now.fi][now.se]);
				break;
			}
			for(int k=0; k<8; k++)
			{
				pi next = mp(now.fi + CX[k], now.se + CY[k]);
				if(next.fi < 0 || next.se < 0) continue;
				if(next.fi >= L || next.se >= L) continue;
				if(Dis[next.fi][next.se] != -1) continue;
				Q.push(next);
				Dis[next.fi][next.se] = Dis[now.fi][now.se] + 1;
			}
		}
	}
	return 0;
}










