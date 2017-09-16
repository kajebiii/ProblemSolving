#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e4 + 100;

int N, Nr[MAX_N];
bool Visit[MAX_N]; int Dis[MAX_N];
int main()
{
	scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	int S, E; scanf("%d%d", &S, &E);
	for(int i=1; i<=N; i++) Dis[i] = 0x7fffffff;
	queue<int> Q; Q.push(S); Dis[S] = 0;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		if(Visit[v]) continue; Visit[v] = true;
		for(int w=v; w>=1; w-=Nr[v])
			if(Visit[w] == false && Dis[w] > Dis[v] + 1)
				Dis[w] = Dis[v] + 1, Q.push(w);
		for(int w=v; w<=N; w+=Nr[v])
			if(Visit[w] == false && Dis[w] > Dis[v] + 1)
				Dis[w] = Dis[v] + 1, Q.push(w);
	}
	if(Dis[E] == 0x7fffffff) Dis[E] = -1;
	printf("%d\n", Dis[E]);
	return 0;
}