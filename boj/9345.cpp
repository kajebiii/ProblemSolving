#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 0x7fffffff, MAX_N = 1e5 + 100;

typedef pair<int, int> pi;

struct IDX
{
	int P; vector<int> val[2];
	IDX(int n)
	{
		for(P=1; P<n; P<<=1);
		val[0] = vector<int>(2*P, INF);
		val[1] = vector<int>(2*P, -INF);
	}
	void update(int v, int k)
	{
		v += P;
		val[0][v] = val[1][v] = k;
		while(v/=2) 
		{
			val[0][v] = min(val[0][v*2], val[0][v*2+1]);
			val[1][v] = max(val[1][v*2], val[1][v*2+1]);
		}
	}
	bool isGood(int a, int b)
	{
		pi res = make_pair(INF, -INF);
		int l = a, r = b;
		a+=P, b+=P;
		while(a<=b)
		{
			if(a%2==1) res.first = min(res.first, val[0][a]), res.second = max(res.second, val[1][a]), a++;
			if(b%2==0) res.first = min(res.first, val[0][b]), res.second = max(res.second, val[1][b]), b--;
			a/=2;b/=2;
		}
		return (res.first == l && res.second == r);
	}
};
int Ix[MAX_N];

int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		int N, M; scanf("%d%d", &N, &M);
		IDX idx = IDX(N);
		for(int i=0; i<N; i++) idx.update(i, i), Ix[i] = i;
		while(M--)
		{
			int k, x, y; scanf("%d%d%d", &k, &x, &y);
			if(k == 1) printf("%s\n", idx.isGood(x, y)?("YES"):("NO"));
			else
			{
				int a = Ix[x], b = Ix[y];
				swap(Ix[x], Ix[y]);
				idx.update(b, x);
				idx.update(a, y);
			}
		}
	}
	return 0;
}