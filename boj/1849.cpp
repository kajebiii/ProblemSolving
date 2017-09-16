#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;

struct IDX
{
	int P; vector<int> Val;
	IDX(int N)
	{
		for(P=1; P<N; P<<=1);
		Val = vector<int>(2*P, 0);
		for(int i=P; i<P+N; i++) Val[i] = 1;
		for(int i=P-1; i>=1; i--) Val[i] = Val[i*2] + Val[i*2+1];
	}
	void update(int v, int k)
	{
		Val[v += P] = k;
		while(v /= 2) Val[v] = Val[v*2] + Val[v*2+1];
	}
	int getKth(int k)
	{
		int v = 1, now = 0;
		while(v < P)
		{
			if(Val[v*2] + now >= k) v *= 2;
			else
			{
				now += Val[v*2];
				v = v*2 + 1;
			}
		}
		return v - P;
	}
};

int N, Ans[MAX_N];
int main()
{
	scanf("%d", &N);
	IDX idx = IDX(N);
	for(int k=1; k<=N; k++)
	{
		int x; scanf("%d", &x);
		int ix = idx.getKth(x+1);
		Ans[ix] = k;
		idx.update(ix, 0);
	}
	for(int i=0; i<N; i++) printf("%d\n", Ans[i]);
	return 0;
}