#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 2e5 + 100;

struct PRO
{
	int d, n;
	PRO(int d_, int n_) : d(d_), n(n_) {}
	bool operator<(const PRO &o) const{return d > o.d;}
};

int N; vector<PRO> Ps;

int main()
{
	scanf("%d", &N); for(int i=0, d, n; i<N; i++) scanf("%d%d", &d, &n), Ps.push_back(PRO(d, n));
	sort(Ps.begin(), Ps.end());
	int PN = Ps.size(), j = 0;
	priority_queue<int> PQ;
	int ans = 0;
	for(int i=N; i>=1; i--)
	{
		while(j < PN && Ps[j].d == i) PQ.push(Ps[j++].n);
		if(!PQ.empty())
		{
			ans += PQ.top();
			PQ.pop();
		}
	}
	printf("%d\n", ans);
	return 0;
}