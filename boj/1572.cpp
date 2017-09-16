#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e5;

int N, K, Nr[MAX_N];

struct IDX
{
	int P; vector<int> Val;
	IDX(int N)
	{
		for(P=1; P<N; P<<=1);
		Val = vector<int>(2*P, 0);
	}
	void updatePlus(int v, int k)
	{
		v += P;
		Val[v] += k;
		while(v/=2) Val[v] = Val[v*2] + Val[v*2+1];
	}
	int getSum(int a, int b)
	{
		int result = 0; a+=P; b+=P;
		while(a <= b)
		{
			if(a%2 == 1) result += Val[a++];
			if(b%2 == 0) result += Val[b--];
			a /= 2; b /= 2;
		}
		return result;
	}
	int getMedium(int K)
	{
		int result = -1;
		for(int l=0, r=65535; l < r; result = l)
		{
			int m = (l + r) >> 1;
			int now = getSum(0, m);
			if(now < (K+1)/2) l = m+1; else r = m;
		}
		return result;
	}
};
int main()
{
	scanf("%d%d", &N, &K);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);

	long long ans = 0;

	IDX idx = IDX(65536);
	for(int i=1; i<=K; i++) idx.updatePlus(Nr[i], 1);
	ans += idx.getMedium(K);
	for(int i=K+1; i<=N; i++)
	{
		idx.updatePlus(Nr[i-K], -1);
		idx.updatePlus(Nr[i]  , +1);
		ans += idx.getMedium(K);
	}
	printf("%lld\n", ans);
	return 0;
}