// =====================================================================================
//
//       Filename:  4963.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 22:29:23
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int UNF[9999], Cnt[9999];
int F(int x)
{
	return UNF[x]==0?x:UNF[x]=F(UNF[x]);
}
void UF(int x, int y)
{
	x = F(x); y = F(y);
	if(x == y) return;
	UNF[x] = y;
	Cnt[y] += Cnt[x];
}

int Map[55][55];

int main() {
	while(true)
	{
		int N, M; cin >> M >> N;
		if(N == 0 && M == 0) break;
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
			scanf("%1d", &Map[i][j]), Cnt[i*M+j] = 1, UNF[i*M+j] = 0;
		int cx[8] = {0, -1, 0, +1, -1, -1, +1, +1};
		int cy[8] = {-1, 0, +1, 0, -1, +1, -1, +1};
		for(int i=0; i<=N+1; i++)
			Map[i][0] = Map[i][M+1] = 0;
		for(int j=0; j<=M+1; j++)
			Map[0][j] = Map[N+1][j] = 0;
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
			if(Map[i][j] == 1) for(int k=0; k<8; k++)
				if(Map[i+cx[k]][j+cy[k]] == 1)
				{
					UF(i*M+j, (i+cx[k])*M+(j+cy[k]));
				}
		int result = 0;
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
			if(UNF[i*M+j] == 0 && Map[i][j] == 1)
				result++;
		printf("%d\n", result);
	}
	return 0;
}










