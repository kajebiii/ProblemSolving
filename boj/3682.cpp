#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int MAX_N = 2e4 + 100;

int N, M;
vector<int> Ed[MAX_N];
int Ix[MAX_N], Gp[MAX_N], IN, GN;
stack<int> St;
int inD[MAX_N], outD[MAX_N];
int getLow(int i)
{
	int low;
	low = Ix[i] = ++IN;
	St.push(i);
	for(int w : Ed[i])
		if(Ix[w] == 0)
			low = min(low, getLow(w));
		else if(Gp[w] == 0)
			low = min(low, Ix[w]);
	if(low == Ix[i])
	{
		GN++;
		while(1)
		{
			int now = St.top(); St.pop();
			Gp[now] = GN;
			if(now == i) break;
		}
	}
	return low;
}
void initGraph()
{
	scanf("%d%d", &N, &M);
	for(int _=0; _<M; _++)
	{
		int x, y; scanf("%d%d", &x, &y);
		Ed[x].push_back(y);
	}
	for(int i=1; i<=N; i++) if(Ix[i] == 0) getLow(i);
	for(int i=1; i<=N; i++)
		for(int w : Ed[i])
			if(Gp[i] != Gp[w])
				inD[Gp[w]]++, outD[Gp[i]]++;
}
int process()
{
	if(GN == 1) {return 0;}
	int a = 0, b = 0;
	for(int i=1; i<=GN; i++)
	{
		if(inD[i] == 0) a++;
		if(outD[i] == 0) b++;
	}
	return max(a, b);
}
void delGraph()
{
	for(int i=1; i<=GN; i++) inD[i] = outD[i] = 0;
	for(int i=1; i<=N; i++)
	{
		vector<int> temp;
		Ed[i].swap(temp);
		Ix[i] = Gp[i] = 0;
	}
	IN = GN = 0;
}
int main()
{
	int T; scanf("%d", &T);
	for(int tc=1; tc<=T; tc++)
	{
		initGraph();
		printf("%d\n", process());
		delGraph();
	}
	return 0;
}