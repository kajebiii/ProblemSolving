#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;

struct IDX
{
	int P; vector<int> val;
	IDX(int n)
	{
		for(P=1; P<n; P<<=1);
		val = vector<int>(2*P, 0);
	}
	void update(int v)
	{
		val[v+=P]++;
		while(v/=2) val[v] = val[v*2] + val[v*2+1];
	}
	int getSum(int a, int b)
	{
		int res = 0;
		a+=P, b+=P;
		while(a<=b)
		{
			if(a%2==1) res += val[a++];
			if(b%2==0) res += val[b--];
			a/=2;b/=2;
		}
		return res;
	}
};

int N; vector<int> Nr;
int Ans[MAX_N];
void getAns(vector<int> &nr, int k)
{
	IDX idx = IDX(N);
	for(int i=0; i<N; i++)
	{
		Ans[(N-1) * (1-k) / 2 + k * i] += k * idx.getSum(nr[i]+1, N-1);
		idx.update(nr[i]);
	}
}

int main()
{

	scanf("%d", &N); 
	Nr = vector<int>(N, 0);
	for(int i=0, x; i<N; i++) scanf("%d", &x),Nr[x-1] = i;
	getAns(Nr, 1);
	reverse(Nr.begin(), Nr.end());
	for(int i=0; i<N; i++) Nr[i] = N-1 - Nr[i];
	getAns(Nr, -1);
	for(int i=0; i<N; i++) printf("%d\n", Ans[i]);
	return 0;
}