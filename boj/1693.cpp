#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 100, LOG_N = 20, INF = 0x7fffffff;

int N, Dy[MAX_N][LOG_N];
vector<int> Edge[MAX_N];

void getDy(int v, int p)
{
	vector<int> child;
	for(int w : Edge[v]) if(w != p) getDy(w, v), child.push_back(w);
	for(int i=1; i<LOG_N; i++)
	{
		Dy[v][i] += i;
		for(int w : child)
		{
			int nowMin = INF;
			for(int j=1; j<LOG_N; j++)
				if(i != j)
					nowMin = min(nowMin, Dy[w][j]);
			Dy[v][i] += nowMin;
		}
	}
	vector<int> temp;
	child.swap(temp);
	return;
}

int main()
{
	scanf("%d", &N);
	for(int i=1; i<N; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Edge[x].push_back(y);
		Edge[y].push_back(x);
	}
	getDy(1, -1);
	int ans = INF;
	for(int i=1; i<LOG_N; i++) 
		ans = min(ans, Dy[1][i]);
	printf("%d\n", ans);
	return 0;
}