#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100, MOD = 1e9 + 7;

struct ED
{
	int to, co;
	ED(int to_, int co_) : to(to_), co(co_) {}
};

int N, S[MAX_N], Sum[MAX_N];
vector<ED> Edge[MAX_N];
void addEdge(int fr, int to, int co)
{
	Edge[fr].push_back(ED(to, co));
	Edge[to].push_back(ED(fr, co));
}

int modCh(int x)
{
	return (x % MOD + MOD) % MOD;
}

int Ans = 0;
void dfs(int v, int p)
{
	S[v] = 1;
	int sum = 0, sumSq = 0;
	int val1 = 0, val2 = 0;
	for(ED &e : Edge[v])
	{
		int w = e.to, c = e.co;
		if(w == p) continue;
		dfs(w, v);
		S[v] += S[w];
		int now = (1ll * Sum[w] * c + c) % MOD;
		sum = (sum + now) % MOD;
		sumSq = (sumSq + 1ll * now * now) % MOD;
		Sum[v] = (Sum[v] + now) % MOD;
	}
	val1 = sum;
	val2 = modCh( (1ll * sum * sum - sumSq) % MOD );
	if(val2 % 2 == 1) val2 += MOD;
	val2 /= 2;

	int val = (val1 + val2) % MOD;
	Ans = (Ans + val) % MOD;
}

int main()
{
	scanf("%d", &N);
	for(int i=1; i<N; i++)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		addEdge(a, b, c);
	}
	dfs(1, -1);
	printf("%d\n", Ans);
	return 0;
}