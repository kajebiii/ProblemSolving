#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

#define mp make_pair
typedef pair<int, int> pi;
int N;
multiset<pi> Sx, Sy;
pi pairSwap(pi o) {return mp(o.second, o.first); }
int getArea()
{
	int dx = Sx.rbegin()->first - Sx.begin()->first;
	int dy = Sy.rbegin()->first - Sy.begin()->first;
	return dx * dy;
}
int choosePoint(int k)
{
	if(k == 3) return getArea();
	vector<pi> chs ={*Sx.begin(), *Sx.rbegin(), pairSwap(*Sy.begin()), pairSwap(*Sy.rbegin())};
	int result = 0x7fffffff;
	for(pi &ch : chs)
	{
		Sx.erase(Sx.find(ch));
		Sy.erase(Sy.find(pairSwap(ch)));
		result = min(result, choosePoint(k+1));
		Sx.insert(ch);
		Sy.insert(pairSwap(ch));
	}
	return result;
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
	int ans = choosePoint(0);
	printf("%d\n", ans);
	return 0;
}