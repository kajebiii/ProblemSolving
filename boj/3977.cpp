#include <stdio.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;

int N, M;
vector<int> Ed[MAX_N];

int D[MAX_N], DN, G[MAX_N], GN; stack<int> S;
int InD[MAX_N];

void initGraph()
{
	scanf("%d%d", &N, &M);
	while(M--)
	{
		int x, y; scanf("%d%d", &x, &y);
		x++; y++;
		Ed[x].push_back(y);
	}
}
int getLow(int v)
{
	int low;
	low = D[v] = ++DN;
	S.push(v);

	for(int w : Ed[v]) 
		if(D[w] == 0) low = min(low, getLow(w));
		else if(G[w] == 0) low = min(low, D[w]);

	if(low != D[v]) return low;
	++GN;
	while(1)
	{
		int now = S.top(); S.pop();
		G[now] = GN;
		if(now == v) break;
	}
	return low;
}
void delGraph()
{
	for(int i=1; i<=N; i++)
	{
		vector<int> temp;
		Ed[i].swap(temp);
		D[i] = G[i] = 0;
	}
	for(int i=1; i<=GN; i++)
		InD[i] = 0;
	DN = GN = 0;
}

int main()
{
	int T; scanf("%d", &T);
	for(int t=0; t<T; t++)
	{
		if(t != 0) puts("");
		initGraph();
		for(int i=1; i<=N; i++) if(D[i] == 0) getLow(i);
		for(int i=1; i<=N; i++) for(int j : Ed[i]) if(G[i] != G[j]) InD[G[j]]++;
		int chk = 0, who = -1;
		for(int i=1; i<=GN; i++) if(InD[i] == 0) chk++, who = i;
		if(chk == 1) {for(int i=1; i<=N; i++) if(G[i] == who) printf("%d\n", i-1);}
		else puts("Confused");
		delGraph();
	}
	return 0;
}