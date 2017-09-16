#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 100;

int N, M, S, E;
vector<int> Ed[MAX_N];

int Ix[MAX_N], IN, Gp[MAX_N], GN; stack<int> St;
int getLow(int v)
{
	int low;
	low = Ix[v] = ++IN;
	St.push(v);
	for(int w : Ed[v])
		if(Ix[w] == 0)		
			low = min(low, getLow(w));
		else if(Gp[w] == 0)	
			low = min(low, Ix[w]);
	if(low != Ix[v]) return low;
	for(GN++; true;)
	{
		int now = St.top(); St.pop();
		Gp[now] = GN;
		if(now == v) break;
	}
	return low;
}
void initGraph()
{
	scanf("%d%d%d%d", &N, &M, &S, &E);
	for(int _=0, a, b; _<M; _++)
		scanf("%d%d", &a, &b), Ed[a].push_back(b);
	getLow(S);

}

vector<int> GEd[MAX_N]; 
int Nr[MAX_N], inD[MAX_N], Dy[MAX_N];
int main()
{
	initGraph();
	for(int i=1; i<=N; i++) if(Ix[i] != 0)
	{
		Nr[Gp[i]]++;
		for(int w : Ed[i]) if(Ix[w] != 0 && Gp[w] != Gp[i])
			GEd[Gp[i]].push_back(Gp[w]), inD[Gp[w]]++;
	}
	queue<int> Q; Q.push(Gp[S]);
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		Dy[v] += Nr[v];
		for(int w : GEd[v])
		{
			Dy[w] = max(Dy[w], Dy[v]);
			if(--inD[w] == 0) Q.push(w);
		}
	}
	printf("%d\n", Dy[Gp[E]]);
	return 0;
}