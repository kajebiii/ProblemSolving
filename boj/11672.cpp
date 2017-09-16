#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 100;

int N, T[MAX_N * 4], P;
vector<int> V[3];

void update(int v, int k)
{
	T[v += P] = k;
	while(v /= 2) T[v] = T[v*2] + T[v*2+1];
}
int getSum(int a, int b)
{
	a += P, b += P;
	int val = 0;
	while(a <= b)
	{
		if(a % 2 == 1) val += T[a++];
		if(b % 2 == 0) val += T[b--];
		a /= 2;
		b /= 2;
	}
	return val;
}
ll getInverse(vector<int> &A, vector<int> &B)
{
	ll val = 0;
	vector<int> ix = vector<int>(N, 0);
	for(int i=0; i<N; i++) ix[B[i]] = i;

	for(int i=1; i<2*P; i++) T[i] = 0;
	for(int p=0; p<N; p++)
	{
		int i = ix[A[N-1-p]];
		update(i, 1);
		val += getSum(0, i-1);
	}
	return val;
}
int main()
{
	scanf("%d", &N);
	for(P=1; P<N; P<<=1);
	for(int k=0; k<3; k++) for(int i=0, x; i<N; i++) scanf("%d", &x), V[k].push_back(x-1);
	ll sum = 0;
	for(int k=0; k<3; k++) sum += getInverse(V[k], V[(k+1)%3]);
	printf("%lld\n", (1ll*N*(N-1) - sum) / 2 );
	return 0;
}