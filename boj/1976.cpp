#include <stdio.h>

const int MAX_N = 2e2 + 10;

int N, M;
int UNF[MAX_N];

int F(int v) {return UNF[v] == v ? v : UNF[v] = F(UNF[v]); }
void U(int a, int b) 
{
	a = F(a), b = F(b);
	UNF[a] = b;
}
int main()
{
	scanf("%d%d", &N, &M);

	for(int i=1; i<=N; i++) UNF[i] = i;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
	{
		int x; scanf("%d", &x);
		if(x == 1) U(i, j);
	}

	int same = 0;
	scanf("%d", &same);
	same = F(same);

	bool ans = true;
	for(int i=1; i<M; i++)
	{
		int x; scanf("%d", &x);
		if(same != F(x)) ans = false;
	}
	if(ans) puts("YES"); else puts("NO");
	return 0;
}