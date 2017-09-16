#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct T
{
	int x, p;
	T() {}
	T(int x_, int p_) : x(x_), p(p_) {}
};
const int MAX_N = 1e5 + 100;

int N; T Ts[MAX_N];
ll Sum[MAX_N];
int main()
{
	scanf("%d", &N); for(int i=1, x, p; i<=N; i++) scanf("%d%d", &x, &p), Ts[i] = T(x, p);
	sort(Ts+1, Ts+N+1, [&](const T &a, const T &b){return a.x < b.x;});
	for(int i=1; i<=N; i++) Sum[i] = Sum[i-1] + Ts[i].p;
	for(int i=1; i<=N; i++)
	{
		if(Sum[N] - Sum[i] <= Sum[i])
		{
			printf("%d\n", Ts[i].x);
			return 0;
		}
	}
	return 0;
}