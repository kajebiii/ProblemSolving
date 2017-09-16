#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;

int N, Nr[MAX_N], Sm[MAX_N];

struct IDX
{
	int P; vector<int> val;
	IDX(int n)
	{
		for(P=1; P<n; P<<=1);
		val = vector<int>(2*P, 1);
		for(int i=P-1; i>=1; i--)
			val[i] = val[i*2] + val[i*2+1];
	}
	void update(int v, int k)
	{
		val[v+=P] = k;
		while(v/=2) val[v] = val[v*2] + val[v*2+1];
	}
	int getKth(int k)
	{
		int ix = 1;
		while(ix < P)
		{
			if(val[ix*2] >= k) ix = ix*2;
			else 
			{
				k -= val[ix*2];
				ix = ix*2 + 1;
			}
		}
		return ix - P;
	}
};

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	for(int i=0; i<N; i++) scanf("%d", &Sm[i]);
	sort(Nr, Nr+N);
	IDX idx = IDX(N);
	vector<int> Ans = vector<int>(N+1, 0);
	for(int i=N-1; i>=0; i--)
	{
		int ix = idx.getKth(Sm[i]+1);
		idx.update(ix, 0);
		Ans[i] = Nr[ix];
	}
	for(int i=0; i<N; i++) printf("%d\n", Ans[i]);
	return 0;
}