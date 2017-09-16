#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 5e2 + 10;

int N, Nr[MAX_N][MAX_N*2], Match[MAX_N*2];
int Dis[MAX_N*2], Ix[MAX_N*2], inQ[MAX_N];
vector<int> Edge[MAX_N*2];
int spsf()
{
	queue<int> Q;
	for(int i=1; i<=N*2; i++) Dis[i] = 1e9, Ix[i] = 0;
	for(int i=1; i<=N; i++) if(Match[i] == 0) Q.push(i), Dis[i] = 0, inQ[i] = 1;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		inQ[v] = 0;
		for(int w=1+N; w<=N+N; w++)
			if(Match[w] == 0)
			{
				if(Dis[w] > Dis[v] + Nr[v][w])
				{
					Dis[w] = Dis[v] + Nr[v][w];
					Ix[w] = v;
				}
			}
			else
			{
				int x = Match[w];
				if(Dis[x] > Dis[v] + Nr[v][w] - Nr[x][w])
				{
					Dis[x] = Dis[v] + Nr[v][w] - Nr[x][w];
					Ix[x] = w; Ix[w] = v;
					if(inQ[x] == 0) inQ[x] = 1, Q.push(x);
				}
			}
	}
	bool havePath = false;
	for(int i=N+1; i<=N*2; i++) if(Dis[i] != 1e9) return i;
	return 0;
}
void addEdge(int i, int j)
{
	Edge[i].push_back(j);
	Edge[j].push_back(i);
}
int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		scanf("%d", &Nr[i][N+j]);

	int cost = 0;
	while(true)
	{
		int last = spsf();
//		printf("%d %d\n", last, Dis[last]);
		if(last == 0) break;
		cost += Dis[last];
		for(int i=last; i!=0; i=Ix[i])
		{
			Match[i] = Ix[i];
			Match[Ix[i]] = i;
			i = Ix[i];
		}
	}
	printf("%d\n", cost);
	return 0;
}