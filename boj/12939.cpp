#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_ND = 5e2 + 10, MOD = 1e9 + 9;

int N, C, L, Node;
int isEnd[MAX_ND], F[MAX_ND], O[MAX_ND];
int Trie[MAX_ND][26];
int Dy[1<<6][55][MAX_ND];

int main()
{
	scanf("%d%d%d", &N, &C, &L);
	for(int l=0; l<N; l++)
	{
		char C[55]; scanf("%s", C);
		int now = 0;
		for(int i=0; C[i]; i++)
		{
			if(Trie[now][C[i]-'a'] == 0)
				Trie[now][C[i]-'a'] = ++Node;
			now = Trie[now][C[i]-'a'];
		}
		isEnd[now] = 1 << l;
	}
	queue<int> Q;for(int i=0; i<26; i++) if(Trie[0][i]) Q.push(Trie[0][i]);
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		if(isEnd[now]) O[now] = now;
		else O[now] = O[F[now]];
		for(int i=0; i<26; i++) if(Trie[now][i])
		{
			int next = Trie[now][i];
			int f = F[now];
			while(f && Trie[f][i] == 0) f = F[f];
			if(Trie[f][i]) F[next] = Trie[f][i];
			Q.push(next);
		}
	}
	Dy[0][0][0] = 1;
	for(int i=1; i<=L; i++)
	{
		for(int n=0; n<=Node; n++)
			for(int s=0; s<(1<<N); s++)
				for(int c=0; c<26; c++)
				{
					int now = n, next = 0;
					while(now && Trie[now][c] == 0) now = F[now];
					if(Trie[now][c]) next = Trie[now][c];

					int o = O[next], ns = s;
					while(isEnd[o])
					{
						ns |= isEnd[o];
						o = O[F[o]];
					}
					Dy[ns][i][next] += Dy[s][i-1][n];
					Dy[ns][i][next] %= MOD;
				}
	}

	int ans = 0;
	for(int i=0; i<(1<<N); i++)
	{
		int cnt = 0;
		for(int o=0; o<N; o++) if(i & (1<<o)) cnt++;
		if(cnt == C)
			for(int n=0; n<=Node; n++)
				ans += Dy[i][L][n], ans %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}