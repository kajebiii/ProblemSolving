#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e5 + 10, MAX_H = 1e3 + 10;

vector<int> Hy[MAX_H], List[MAX_N];
bool Chk[MAX_H], Visit[MAX_N]; int Dis[MAX_N];
int N, K, H;

int main()
{
	scanf("%d%d%d", &N, &K, &H);
	for(int i=0; i<H; i++) for(int j=0, x; j<K; j++) scanf("%d", &x), Hy[i].push_back(x), List[x].push_back(i);
	queue<int> Q; Dis[1] = 1; Q.push(1);
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		if(Visit[v] == true) continue;
		Visit[v] = true;
		for(int q : List[v])
		{
			if(Chk[q] == true) continue;
			Chk[q] = true;
			for(int w : Hy[q]) if(Visit[w] == false && (Dis[w] == 0 || Dis[w] > Dis[v] + 1))
			{
				Dis[w] = Dis[v] + 1;
				Q.push(w);
			}
		}
	}
	if(Dis[N] == 0) Dis[N] = -1;
	printf("%d\n", Dis[N]);
	return 0;
}