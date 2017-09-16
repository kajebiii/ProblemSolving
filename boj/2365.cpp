// =====================================================================================
//
//       Filename:  2365.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/12/2016 16:55:32
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 55;
const int INF = 0x7fffffff;

int N, S, E;
int Capa[MAX_N * 2][MAX_N * 2], Flow[MAX_N * 2][MAX_N * 2];
int AnsMin, Ans[MAX_N * 2][MAX_N * 2];

void INPUT()
{
	scanf("%d", &N);
	S = 0; E = 2 * N + 1;
	for(int i=1; i<=N; i++)
	{
		int x; scanf("%d", &x);
		Capa[S][i] = x;
	}
	for(int i=1; i<=N; i++)
	{
		int x; scanf("%d", &x);
		Capa[N+i][E] = x;
	}
}

bool canFlow(int maxF)
{
	for(int i=S; i<=E; i++) for(int j=S; j<=E; j++) Flow[i][j] = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) Capa[i][N+j] = maxF;
	int total = 0;
	vector<int> p;
	while(true)
	{
		p = vector<int>(E + 1, -1);
		queue<int> q;
		q.push(S);

		while(!q.empty() && p[E] == -1)
		{
			int v = q.front(); q.pop();
			for(int i=S; i<=E; i++)
				if(Capa[v][i] - Flow[v][i] > 0 && p[i] == -1)
				{
					q.push(i);
					p[i] = v;
				}
		}

		if(p[E] == -1) break;
		
		int amount = INF;
		for(int now = E; now != S; now = p[now])
			amount = min(Capa[p[now]][now] - Flow[p[now]][now], amount);

		for(int now = E; now != S; now = p[now])
		{
			Flow[p[now]][now] += amount;
			Flow[now][p[now]] -= amount;
		}

		total += amount;
	}

	int maxTotal = 0;
	for(int i=1; i<=N; i++)
		maxTotal += Capa[S][i];

	return maxTotal == total;
}

int main()
{
	INPUT();

	int s = 0, e = 1e5, m;
	
	while(s <= e)
	{
		m = (s + e) / 2;
		if(canFlow(m) == true)
		{
			AnsMin = m;
			for(int i=1; i<=N; i++)
				for(int j=N+1; j<=2*N; j++)
					Ans[i][j] = Flow[i][j];
			e = m - 1;
		}
		else
			s = m + 1;
	}

	printf("%d\n", AnsMin);
	for(int i=1; i<=N; i++, printf("\n"))
		for(int j=N+1; j<=2*N; j++)
			printf("%d ", Ans[i][j]);

	return 0;
}




