#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const int MAX_N = 5e3 + 100, INF = 0x7fffffff;

int N, M;
vector<int> Ed[MAX_N];

int D[MAX_N], DN, G[MAX_N], GN, outD[MAX_N]; stack<int> S;

void initGraph()
{
	scanf("%d", &M);
	while(M--)
	{
		int x, y; scanf("%d%d", &x, &y);
		Ed[x].push_back(y);
	}
}
void delGraph()
{
	for(int i=1; i<=N; i++)
	{
		D[i] = G[i] = 0;
		vector<int> temp;
		Ed[i].swap(temp);
	}
	for(int i=1; i<=GN; i++)
		outD[i] = 0;
	DN = GN = 0;
}

int getLow(int v)
{
	int low;
	low = D[v] = ++DN;
	S.push(v);
	for(int w : Ed[v]) low = min(low, D[w]==0?getLow(w):G[w]==0?D[w]:INF);
	
	if(low == D[v])
		for(++GN; 1; )
		{
			int now = S.top(); S.pop();
			G[now] = GN;
			if(now == v) break;
		}
	return low;
}

int main()
{
	while(1)
	{
		scanf("%d", &N);
		if(N == 0) break;
		initGraph();
		for(int i=1; i<=N; i++) if(D[i] == 0) getLow(i);
		for(int i=1; i<=N; i++) for(int j : Ed[i]) if(G[i] != G[j])
			outD[G[i]]++;
		for(int i=1; i<=N; i++) if(outD[G[i]] == 0) printf("%d ", i);
		puts("");
		delGraph();
	}
	return 0;
}