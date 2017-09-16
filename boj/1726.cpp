// =====================================================================================
//
//       Filename:  1726.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 00:45:38
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 111;

int N, M;
int Map[MAX_N][MAX_N];
int Cnt[MAX_N * MAX_N * 4];

queue< pair< pair<int, int> , int> > Q;

pair< pair<int, int>, int> P(int x, int y, int d)
{
	return make_pair(make_pair(x, y), d);
}
int C(int x, int y, int d)
{
	return (x * M + y) * 4 + d;
}
int L[5] = {0, 3, 4, 1, 2};
int R[5] = {0, 4, 3, 2, 1};

void IfPush(int x, int y, int d, int k)
{
	if(Cnt[C(x, y, d)] != 0) return;
	Cnt[C(x, y, d)] = k + 1;
	Q.push(P(x, y, d));
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%d", &Map[i][j]), Map[i][j] = 1 - Map[i][j];

	int x, y, d; scanf("%d%d%d", &x, &y, &d);
	Q.push(P(x, y, d));
	Cnt[C(x, y, d)] = 1;
	scanf("%d%d%d", &x, &y, &d);
	
	while(!Q.empty())
	{
		int a, b, k;
		a = Q.front().first.first;
		b = Q.front().first.second;
		k = Q.front().second;

		if(a == x && b == y && d == k)
		{
			printf("%d\n", Cnt[C(a, b, k)] - 1);
			return 0;
		}

		Q.pop();
		IfPush(a, b, R[k], Cnt[C(a, b, k)]);
		IfPush(a, b, L[k], Cnt[C(a, b, k)]);

		int cx[5] = {0, 0, 0, +1, -1};
		int cy[5] = {0, +1, -1, 0, 0};
		for(int o=1; o<=3; o++)
		{
			int nx = a + cx[k]*o;
			int ny = b + cy[k]*o;
			if(nx < 0 || ny < 0) break;
			if(Map[nx][ny] == 0) break;
			IfPush(nx, ny, k, Cnt[C(a, b, k)]);
		}
	}

	return 0;
}












