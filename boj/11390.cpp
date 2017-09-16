#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX_N = 50;

typedef long long ll;

int A, B, N;
ll C[MAX_N][MAX_N], K;

int main()
{
	scanf("%d%d%d%lld", &A, &B, &N, &K);
	for(int i=0, j; i<=N; i++) for(C[i][0]=1, j=1; j<=i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
	if(A > B) swap(A, B);

	ll sum = 0;
	for(int i=0; i<=N; i++)
	{
		sum += C[N][i];
		if(sum >= K)
		{
			double a = log(A), b = log(B), h = log(2), ab = log(A*A+B*B);
			printf("%.15f\n", a+b-h + 2*a*i + 2*b*(N-i) - ab*N);
			break;
		}
	}
	return 0;
}