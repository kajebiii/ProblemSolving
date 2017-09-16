#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> pi;

const int MAX_N = 3e3 + 100;
int N; pi Pt[MAX_N];
set<pi> S;
int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &N);
		S.clear();
		for(int i=1; i<=N; i++) scanf("%d%d", &Pt[i].first, &Pt[i].second);
		for(int i=1; i<=N; i++) Pt[i].first *= 2, Pt[i].second *= 2;
		for(int i=1; i<=N; i++) S.insert(Pt[i]);

		int ans = 0;
		for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++)
		{
			int dx = Pt[j].first - Pt[i].first; dx /= 2;
			int dy = Pt[j].second - Pt[i].second; dy /= 2;
			int square = dx * dx + dy * dy;
			if(ans >= square) continue;

			pi other = make_pair(Pt[i].first + dx - dy, Pt[i].second + dy + dx);
			pi diago = make_pair(Pt[i].first + dx + dy, Pt[i].second + dy - dx);

			if(S.count(other) == 1 && S.count(diago) == 1)
				ans = max(ans, square);
		}
		printf("%d\n", ans / 2);
	}
	return 0;
}