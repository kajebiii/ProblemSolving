#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> pi;
const int MAX_N = 35e3 + 100;

struct C
{
	int t, v;
	bool operator<(const C &o) const{return t < o.t;}
};
int N; C Nr[MAX_N];
int ggcd(int a, int b) {return b==0?a:ggcd(b, a%b); }
int main()
{
	while(scanf("%d", &N) == 1)
	{
		for(int i=1; i<=N; i++) scanf("%d%d", &Nr[i].t, &Nr[i].v);
		sort(Nr+1, Nr+N+1);

		int ans = 1;
		for(int i=1; i<=N; i++)
		{
			if(ans >= N-i+1) break;
			int base = 1;
			map<pi, int> Mp;
			for(int j=i+1; j<=N; j++)
			{
				if(Nr[j].t > Nr[i].t + (100 + Nr[i].v - 1) / Nr[i].v ) break;
				// (t - t1) = (t2 - t1) v2 / (v2 - v1)
				int a = (Nr[j].t - Nr[i].t) * Nr[j].v;
				int b = Nr[j].v - Nr[i].v;
//				printf("%d %d : %d / %d\n", i, j, a, b);
				if(b < 0) a *= -1, b *= -1;

				if(a < 0) continue;
				if(b == 0)
				{
					if(a == 0) base++;
					continue;
				}
				// a / b <= 100 / v1
				if(1ll * a * Nr[i].v <= 100 * b)
				{
					int g = ggcd(a, b);
					Mp[make_pair(a / g, b / g)]++;
				}
			}
			int now = 0;
			for(auto &t : Mp) now = max(now, t.second);
			ans = max(ans, now + base);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}