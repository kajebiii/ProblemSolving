#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct ED
{
	int x, y, c;
	ED(int x_, int y_, int c_) : x(x_), y(y_), c(c_) {}
};

const int MAX_N = 2e5 + 100;

int N, M, UNF[MAX_N];
int F(int v) {return UNF[v]==v?v:UNF[v]=F(UNF[v]); }
bool U(int a, int b) 
{
	if(F(a) == F(b)) return false;
	UNF[F(a)] = F(b); 
	return true;
}

int main()
{
	while(1)
	{
		scanf("%d%d", &N, &M);
		if(N+M == 0) break;
		vector<ED> Ed;
		int sum = 0;
		while(M--)
		{
			int x, y, c; scanf("%d%d%d", &x, &y, &c);
			Ed.push_back(ED(x, y, c));
			sum += c;
		}
		sort(Ed.begin(), Ed.end(), [&](ED &a, ED &b)
		{
			return a.c < b.c;
		});
		for(int i=0; i<N; i++) UNF[i] = i;
		int ans = 0;
		for(ED &e : Ed) if(U(e.x, e.y)) ans += e.c;
		printf("%d\n", sum - ans);
	}
	return 0;
}