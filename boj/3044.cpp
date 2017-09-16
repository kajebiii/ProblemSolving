#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e4 + 100, MOD = 1e9;

vector<int> Ed[2][MAX_N];
int N, M, canV[2][MAX_N];

void getCanV(int g, int first)
{
	queue<int> Q; Q.push(first); canV[g][first] = 1;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		for(int w : Ed[g][v]) if(canV[g][w] == 0) canV[g][w] = 1, Q.push(w);
	}
}
void getInput()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<M; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		Ed[0][x].push_back(y);
		Ed[1][y].push_back(x);
	}
	for(int k=0; k<2; k++) getCanV(k, k+1);
}

int Dy[MAX_N], State[MAX_N]; bool haveCycle, isBig[MAX_N];
int getDy(int v)
{
	if(State[v] == 1) { haveCycle = true; return 0; }
	if(State[v] == 2) return Dy[v];
	State[v] = 1; Dy[v] = 0;
	if(v == 1) Dy[v] = 1;
	for(int w : Ed[1][v]) if(canV[0][w] == 1 && canV[1][w] == 1)
	{
		Dy[v] = Dy[v] + getDy(w);
		isBig[v] = (Dy[v] >= MOD) | isBig[w];
		Dy[v] %= MOD;
	}
	State[v] = 2;
	return Dy[v];
}
int main()
{
	getInput();
	for(int i=1; i<=N; i++) Dy[i] = -1;
	int ans = getDy(2);
	if(haveCycle) printf("inf\n");
	else if(isBig[2]) printf("%09d\n", ans);
	else printf("%d\n", ans);
	return 0;
}