#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

const int MAX_N = 3e4 + 100;

typedef pair<int, int> pi;

int N, K, S;
deque<pi> Le, Ri;

int getDis(deque<pi> &list)
{
	sort(list.begin(), list.end());
	int val = 0;

	int rest = 0;
	while(!list.empty())
	{
		int x, p;
		tie(x, p) = list.front(); list.pop_front();
		int minV = min(p, rest);
		p -= minV;
		rest -= minV;

		val += (S-x) * 2 * (p / K);
		p %= K;
		if(p > 0)
		{
			val += (S-x) * 2;
			rest += K-p;
		}
	}
	return val;
}
int main()
{
	scanf("%d%d%d", &N, &K, &S);
	for(int i=0; i<N; i++)
	{
		int x, p; scanf("%d%d", &x, &p);
		if(x < S) Le.push_back(make_pair(x, p));
		else Ri.push_back(make_pair(2*S-x, p));
	}
	printf("%d\n", getDis(Le) + getDis(Ri));
	return 0;
}