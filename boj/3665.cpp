#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 5e2 + 50;

bool Edge[MAX_N][MAX_N]; // Edge[a][b] : Does a win b?
int N, Nr[MAX_N], Ans[MAX_N];

int main()
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d", &N);
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
		for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++) Edge[Nr[i]][Nr[j]] = true, Edge[Nr[j]][Nr[i]] = false;
		int Q; scanf("%d", &Q);
		for(int _=1; _<=Q; _++)
		{
			int a, b; scanf("%d%d", &a, &b);
			Edge[a][b] = !Edge[a][b];
			Edge[b][a] = !Edge[b][a];
		}
		vector<int> wins;
		for(int i=1; i<=N; i++)
		{
			int win = 0;
			for(int j=1; j<=N; j++) win += Edge[i][j];
			wins.push_back(win);
			Ans[N-win] = i;
		}
		sort(wins.begin(), wins.end());
		wins.erase(unique(wins.begin(), wins.end()), wins.end());
		if(wins.size() == N) for(int i=1; i<=N; i++) printf("%d ", Ans[i]);
		else printf("IMPOSSIBLE");
		puts("");
	}
	return 0;
}