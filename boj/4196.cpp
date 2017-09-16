#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;

int N, M;
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
	scanf("%d%d", &N, &M);
	for(int _=0, a, b; _<M; _++)
		scanf("%d%d", &a, &b), Ed[a].push_back(b);
	for(int i=1; i<=N; i++) if(Ix[i] == 0) getLow(i);
}

vector<int> GEd[MAX_N]; 
int Nr[MAX_N], inD[MAX_N];

void delGraph()
{
	for(int i=1; i<=N; i++)
	{
		Ix[i] = Gp[i] = 0;
		vector<int> temp;
		Ed[i].swap(temp);
	}
	for(int i=1; i<=GN; i++)
	{
		vector<int> temp;
		GEd[i].swap(temp);
		Nr[i] = inD[i] = 0;
	}
	IN = GN = 0;
}
int main()
{
	int T; scanf("%d", &T);
	for(int _=0; _<T; _++)
	{
		initGraph();
		for(int i=1; i<=N; i++)
			for(int w : Ed[i]) if(Gp[w] != Gp[i])
				GEd[Gp[i]].push_back(Gp[w]), inD[Gp[w]]++;
		int ans = 0;
		for(int i=1; i<=GN; i++) if(inD[i] == 0) ans++;
		printf("%d\n", ans);
		delGraph();
	}

	return 0;
}