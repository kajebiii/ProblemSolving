#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct MEAT
{
	int m, p;
	MEAT() {}
	MEAT(int m_, int p_) : m(m_), p(p_) {}
	bool operator<(const MEAT &o) const
	{
		if(p != o.p) return p < o.p;
		return m > o.m;
	}
};
int N, M;
MEAT List[111111];

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0, m, p; i<N; i++) scanf("%d%d", &m, &p), List[i] = MEAT(m, p);
	sort(List, List+N);
	int ans = -1, sum = 0, price = 0;
	for(int i=0; i<N; i++)
	{
		if(i == 0 || List[i-1].p != List[i].p) price = 0;
		sum += List[i].m;
		price += List[i].p;
		if(sum >= M) ans = min(ans==-1?0x7fffffff:ans, price);
	}
	printf("%d\n", ans);
	return 0;
}