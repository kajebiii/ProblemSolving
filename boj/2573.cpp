// =====================================================================================
//
//       Filename:  2573.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 23:22:05
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
const int MAX_N = 333;

int N, M, Map[MAX_N][MAX_N];
int Memo[MAX_N][MAX_N], Chk[MAX_N][MAX_N];

int main() {
	cin >> N >> M; for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &Map[i][j]);
	bool find = false;
	int time = 0;

	do
	{
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) Memo[i][j] = 0;
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) 
			for(int k=0; k<4; k++) 
			{
				pi n = mp(i, j) + Ch[k];
				if(Map[n.fi][n.se] == 0)
					Memo[i][j]++;
			}
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
			Map[i][j] -= Memo[i][j], Map[i][j] = max(Map[i][j], 0);

		time++;
		int cnt = 0;
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		{
			if(Map[i][j] == 0 || Chk[i][j] == time) continue;
			queue<pi> Q; Q.push(mp(i, j));
			while(!Q.empty())
			{
				pi now = Q.front(); Q.pop();
				for(int k=0; k<4; k++)
				{
					pi next = now + Ch[k];
					if(Map[next.fi][next.se] == 0 || Chk[next.fi][next.se] == time) continue;
					Q.push(next);
					Chk[next.fi][next.se] = time;
				}
			}
			cnt++;
		}
		if(cnt >= 2) {printf("%d\n", time); find = true;break;}
		if(cnt == 0) break;
	}while(1);

	if(!find) printf("0");
	return 0;
}










