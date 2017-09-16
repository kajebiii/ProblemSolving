#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;

struct LINE
{
	int a, b, c;
	LINE(int a_, int b_, int c_):a(a_),b(b_),c(c_){}
	const bool operator<(const LINE &o) const{return c < o.c;}
};
vector<LINE> L;
int N, M, UNF[MAX_N];
int Find(int v){return UNF[v]==v?v:UNF[v]=Find(UNF[v]);}
void Union(int a, int b)
{
	a = Find(a); b = Find(b);
	UNF[a] = b;
}
int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<M; i++)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		L.push_back(LINE(a, b, c));
	}
	for(int i=1; i<=N; i++) UNF[i] = i;
	sort(L.begin(), L.end());

	long long ans = 0; int cnt = 2;
	for(LINE &l : L)
	{
		if(Find(l.a) == Find(l.b)) continue;
		Union(l.a, l.b);
		ans += l.c;
		cnt++;
		if(cnt == N) break;
	}
	printf("%lld\n", ans);
	return 0;
}