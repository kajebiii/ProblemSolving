#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 1e3 + 10;

int N, K, To[MAX_N], Nr[MAX_N], inD[MAX_N];
bool Dy[MAX_N * 2];
int main()
{
	scanf("%d%d", &N, &K);
	for(int i=1; i<=N; i++)
	{
		scanf("%d", &To[i]);
		Nr[i] = 1;
		inD[To[i]]++;
	}
	queue<int> Q;
	for(int i=1; i<=N; i++) if(inD[i] == 0) Q.push(i);
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		Nr[To[v]] += Nr[v];
		if(--inD[To[v]] == 0) Q.push(To[v]);
	}
	Dy[0] = true;
	for(int i=1; i<=N; i++) if(inD[i] != 0)
	{
		int v = i, cnt = 0, sum = 0;
		while(inD[v] != 0)
		{
			inD[v]--;
			sum += Nr[v];
			cnt++;
			v = To[v];
		}
		for(int k=N; k>=0; k--) if(Dy[k])
			for(int l=k+cnt; l<=k+sum; l++)
				Dy[l] = true;
	}
	int ans = 0;
	for(int k=0; k<=K; k++) if(Dy[k]) ans = k;
	printf("%d\n", ans);
	return 0;
}