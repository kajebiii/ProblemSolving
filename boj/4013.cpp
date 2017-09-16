#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAX_N = 5e5 + 500;

int N, M, Nr[MAX_N], S, GNr[MAX_N];
bool isR[MAX_N], GisR[MAX_N];
vector<int> Ed[MAX_N];
vector<int> GEd[MAX_N];

int Ix[MAX_N], Gp[MAX_N], Lv, GN;
stack<int> St;
int getLow(int v)
{
	int low;
	low = Ix[v] = ++Lv;
	St.push(v);
	for(int w : Ed[v])
		if(Ix[w] == 0)
			low = min(low, getLow(w));
		else if(Gp[w] == 0)
			low = min(low, Ix[w]);

	if(low == Ix[v])
	{
		GN++;
		while(1)
		{
			int now = St.top(); St.pop();
			Gp[now] = GN;
			if(now == v) break;
		}
	}
	return low;
}
void init()
{
	scanf("%d%d", &N, &M);
	for(int _=0; _<M; _++)
	{
		int a, b; scanf("%d%d", &a, &b);
		Ed[a].push_back(b);
	}
	for(int i=1; i<=N; i++)
		scanf("%d", &Nr[i]);
	scanf("%d", &S); int K; scanf("%d", &K);
	for(int _=0, x; _<K; _++) scanf("%d", &x), isR[x] = true;
}

int inD[MAX_N], Dy[MAX_N], Chk[MAX_N];
void dfs(int v)
{
	Chk[v] = 1; for(int w : GEd[v]) if(Chk[w] == 0) dfs(w);
}
int main()
{
	init();
	for(int i=1; i<=N; i++) if(Ix[i] == 0) getLow(i);
	for(int i=1; i<=N; i++)
	{
		for(int w : Ed[i])
			if(Gp[i] != Gp[w])
				GEd[Gp[i]].push_back(Gp[w]);
		GisR[Gp[i]] |= isR[i];
		GNr[Gp[i]] += Nr[i];
	}
	queue<int> Q;
	dfs(Gp[S]);
	for(int i=1; i<=GN; i++) if(Chk[i] == 1)
		for(int w : GEd[i])
			if(Chk[w] == 1) inD[w]++;
	Q.push(Gp[S]);
	int ans = -1;
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		Dy[now] += GNr[now];
		if(GisR[now]) ans = max(ans, Dy[now]);
		for(int w : GEd[now])
		{
			Dy[w] = max(Dy[w], Dy[now]);
			if(--inD[w] == 0) Q.push(w);
		}
	}
	printf("%d\n", ans);
	return 0;
}