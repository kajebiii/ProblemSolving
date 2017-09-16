#include <stdio.h>

typedef long long ll;

ll A, B;
const int MOD = 1e9;
struct MAT
{
	int nr[2][2];
	MAT(int k)
	{
		if(k == 0)
			nr[0][0] = nr[0][1] = nr[1][0] = 1, nr[1][1] = 0;
		else
			nr[0][0] = nr[1][1] = 1, nr[1][0] = nr[0][1] = 0;
	}
	MAT operator*(MAT Y)
	{
		MAT T = MAT(1);
		T.nr[0][0] = T.nr[1][1] = 0;
		for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++)
			T.nr[i][j] += 1ll * nr[i][k] * Y.nr[k][j] % MOD,
			T.nr[i][j] %= MOD;
		return T;
	}
};
int get(ll n)
{
	MAT P = MAT(0), A = MAT(1);
	while(n)
	{
		if(n % 2)
			A = A * P;
		P = P * P;
		n /= 2;
	}
	return A.nr[1][0];
}
int main()
{
	scanf("%lld%lld", &A, &B);
	printf("%d\n", (get(B+2) - get(A+1) + MOD) % MOD );
	return 0;
}