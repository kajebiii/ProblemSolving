// =====================================================================================
//
//       Filename:  2583.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 19:19:04
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
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 111;

int N, M, T;
vector<int> Ans;
int Nr[MAX_N][MAX_N];

int main() {
	cin >> M >> N >> T;
	for(;T--;)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for(int i=a; i<c; i++) for(int j=b; j<d; j++)
			Nr[i][j] = 1;
	}
	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
	{
		if(Nr[i][j]) continue;
		queue<pi> Q;

		int cnt = 0;
		Q.push(mp(i, j));
		Nr[i][j] = 1;
		while(!Q.empty())
		{
			pi now = Q.front(); Q.pop();
			cnt++;
			for(int k=0; k<4; k++)
			{
				pi next = mp(now.fi + CX[k], now.se + CY[k]);
				if(next.fi < 0 || next.fi >= N || next.se < 0 || next.se >= M) continue;
				if(Nr[next.fi][next.se] == 1) continue;
				Q.push(next);
				Nr[next.fi][next.se] = 1;
			}
		}
		Ans.push_back(cnt);
	}
	cout << Ans.size() << endl;
	sort(Ans.begin(), Ans.end());
	for(int x : Ans)
		cout << x << " ";
	return 0;
}










