#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_ND = 101101;

int N, Query;
bool isEnd[MAX_ND];
int F[MAX_ND], O[MAX_ND];
int Trie[MAX_ND][26], Node;
int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		char c[111];
		scanf("%s", c);
		int now = 0;
		for(int j=0; c[j]; j++)
		{
			if(Trie[now][c[j]-'a'] == 0)
				Trie[now][c[j]-'a'] = ++Node;
			now = Trie[now][c[j]-'a'];
		}
		isEnd[now] = true;
	}
	queue<int> Q;
	for(int i=0; i<26; i++) if(Trie[0][i] != 0)
	{
		int next = Trie[0][i];
		F[next] = 0;
		Q.push(next);
	}
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		if(isEnd[now]) O[now] = now;
		else O[now] = O[F[now]];
		for(int i=0; i<26; i++) if(Trie[now][i] != 0)
		{
			int next = Trie[now][i];
			int f = F[now];
			while(f && Trie[f][i] == 0) f = F[f];
			if(Trie[f][i] != 0) f = Trie[f][i];
			F[next] = f;
			Q.push(next);
		}
	}

	scanf("%d", &Query);
	for(int _=0; _<Query; _++)
	{
		char S[10101]; scanf("%s", S);
		int now = 0;
		bool find = false;
		for(int i=0; S[i]; i++)
		{
			int l = S[i] - 'a';
			while(now && Trie[now][l] == 0) now = F[now];
			if(Trie[now][l] != 0) now = Trie[now][l];
			if(O[now] != 0) {find = true; break;}
		}
		find?puts("YES"):puts("NO");
	}
	return 0;
}
