#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

#define mp make_pair
typedef pair<int, int> pi;
int N;
multiset<pi> Sx, Sy;
pi pairSwap(pi o) {return mp(o.second, o.first); }
int getArea(pi ch)
{
	Sx.erase(Sx.find(ch));
	Sy.erase(Sy.find(pairSwap(ch)));
	int dx = Sx.rbegin()->first - Sx.begin()->first;
	int dy = Sy.rbegin()->first - Sy.begin()->first;
	Sx.insert(ch);
	Sy.insert(pairSwap(ch));
	return dx * dy;
}
int main()
{
	scanf("%d", &N);
	for(int i=0, x, y; i<N; i++)
	{
		scanf("%d%d", &x, &y);
		Sx.insert(mp(x, y));
		Sy.insert(mp(y, x));
	}
	int ans = 0x7fffffff;
	ans = min(ans, getArea(*Sx.begin()));
	ans = min(ans, getArea(*Sx.rbegin()));
	ans = min(ans, getArea(pairSwap(*Sy.begin())));
	ans = min(ans, getArea(pairSwap(*Sy.rbegin())));
	printf("%d\n", ans);
	return 0;
}