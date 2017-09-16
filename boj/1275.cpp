#include <stdio.h>
#include <algorithm>

using namespace std;

int N, Q;
struct IX
{
	long long *T;
	int P;
	IX(int N)
	{
		for(P=1; P<N; P<<=1);
		T = new long long[P*2];
		for(int i=0; i<P*2; i++) T[i] = 0;
	}
	void update(int x, int k)
	{
		T[x = x + P] = k;
		while(x /= 2) T[x] = T[x*2] + T[x*2 + 1];
	}
	long long getSum(int a, int b)
	{
		a = a + P, b = b + P;
		long long result = 0;
		while(a <= b)
		{
			if(a % 2 == 1) result += T[a++];
			if(b % 2 == 0) result += T[b--];
			a /= 2, b /= 2;
		}
		return result;
	}
};
int main()
{
	scanf("%d%d", &N, &Q);
	IX ix = IX(N);

	for(int i=0; i<N; i++)
	{
		int b; scanf("%d", &b);
		ix.update(i, b);
	}
	for(int i=0; i<Q; i++)
	{
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b); x--,y--,a--,b;
		if(x > y) swap(x, y);
		printf("%lld\n", ix.getSum(x, y));
		ix.update(a, b);
	}

	return 0;
}