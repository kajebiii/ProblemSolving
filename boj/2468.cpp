// =====================================================================================
//
//       Filename:  2468.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 12:30:55
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
const int MAX_N = 111;

int N, Nr[MAX_N][MAX_N];
int Chk[MAX_N][MAX_N];

int main() {
	cin >> N;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		scanf("%d", &Nr[i][j]);

	int ans = 1;
	for(int c=1; c<=100; c++)
	{
		int nowAns = 0;
		for(int i=0; i<=N+1; i++) for(int j=0; j<=N+1; j++)
			if(Nr[i][j] <= c) Chk[i][j] = c;
		for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		{
			if(Chk[i][j] == c) continue;
			queue<pi> Q;
			Q.push(mp(i, j));
			Chk[i][j] = c;
			while(!Q.empty())
			{
				int cx[4] = {-1, 0, 1, 0}, cy[4] = {0, -1, 0, 1};
				pi now = Q.front(); Q.pop();
				for(int k=0; k<4; k++)
				{
					pi next = mp(now.fi + cx[k], now.se + cy[k]);
					if(Chk[next.fi][next.se] == c) continue;
					Q.push(next);
					Chk[next.fi][next.se] = c;
				}
			}
			nowAns++;
		}
		ans = max(ans, nowAns);
	}

	cout << ans << endl;
	
	return 0;
}










