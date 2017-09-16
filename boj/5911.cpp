#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct G
{
	int p, s;
	G(int p_, int s_) : p(p_), s(s_) {}
	bool operator<(const G &o)const{return p+s<o.p+o.s;}
};
typedef long long ll;
vector<G> Gs;
int N; ll B;

int main()
{
	scanf("%d%lld", &N, &B);
	for(int i=0; i<N; i++)
	{
		int p, s;
		scanf("%d%d", &p, &s);
		Gs.push_back(G(p, s));
	}
	sort(Gs.begin(), Gs.end());
	int ans = 0;
	for(int i=0; i<N; i++)
	{
		ll nowB = B;
		if(nowB < Gs[i].p/2 + Gs[i].s) continue;
		int now = 1;
		nowB -= Gs[i].p/2 + Gs[i].s;	
		for(int j=0; j<N; j++)
		{
			if(j == i) continue;
			if(nowB < Gs[j].p + Gs[j].s) break;
			nowB -= Gs[j].p + Gs[j].s;
			now++;
		}
		ans = max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}