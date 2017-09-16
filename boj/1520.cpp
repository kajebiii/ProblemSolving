// =====================================================================================
//
//       Filename:  1520.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 10:48:12
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

const int MAX_N = 5e2 + 50;

int N, M, Map[MAX_N][MAX_N];

int cN(int x, int y)
{
	return x * M + y;
}
pi cP(int k)
{
	return mp((k-1)/M, (k-1)%M+1);
}

int Deg[MAX_N*MAX_N];
int Dy[MAX_N*MAX_N];
vector<int> V[MAX_N*MAX_N];
queue<int> Q;

int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) cin >> Map[i][j];

	int cx[4] = {0, 1, 0, -1}, cy[4] = {1, 0, -1, 0};
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) 
	{
		int cnt = 0;
		for(int k=0; k<4; k++)
			if(Map[i][j] < Map[i+cx[k]][j+cy[k]])
			{
				cnt++;
				V[cN(i+cx[k], j+cy[k])].push_back(cN(i, j));
			}
		if(cnt == 0)
			Q.push(cN(i, j));
		Deg[cN(i, j)] = cnt;
	}

	Dy[cN(1, 1)] = 1;

	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		for(auto x : V[now])
		{
			Deg[x]--;
			Dy[x] += Dy[now];
			if(Deg[x] == 0)
			{
				Q.push(x);
			}
		}
	}

	cout << Dy[cN(N, M)];
	
	return 0;
}










