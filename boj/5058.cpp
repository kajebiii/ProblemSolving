#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 2e4 + 100;
struct D
{
	int h, w;
	const bool operator<(const D &o) const
	{
		if(o.h == h) return w < o.w;
		return h > o.h;
	}
}Doll[MAX_N];
int N;
int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d%d", &Doll[i].h, &Doll[i].w);
		sort(Doll, Doll+N);
		multiset<int> S; S.clear();
		int cnt = 0;
		for(int i=0; i<N; i++)
		{
			auto it = S.upper_bound(Doll[i].w);
			if(it == S.end()) S.insert(Doll[i].w), cnt++;
			else
			{
				S.erase(it);
				S.insert(Doll[i].w);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}