#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 1e2 + 10;
int N, M, K;
vector<int> Edge[MAX_N];
void makeGraph()
{
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i<K; i++)
	{
		long double x, y; scanf("%Lf%Lf", &x, &y);
		int a = (int)x + 1, b = (int)y + 1;
		Edge[a].push_back(b);
	}
}
void deleteGraph()
{
	for(int i=1; i<=N; i++)
	{
		vector<int> temp;
		Edge[i].swap(temp);
	}
}

bool Visit[MAX_N]; int Match[MAX_N];
bool findMatch(int v)
{
	if(Visit[v] == true) return false;
	Visit[v] = true;
	for(int w : Edge[v])
		if(Match[w] == 0 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}
int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		makeGraph();
		int flow = 0;
		for(int i=1; i<=M; i++) Match[i] = 0;
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++) Visit[j] = false;
			if(findMatch(i)) flow++;
		}
		printf("%d\n", flow);
		deleteGraph();
	}
	return 0;
}