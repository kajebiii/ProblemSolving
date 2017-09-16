#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll A, B, N;
ll gcd(ll x, ll y) {return y==0?x:gcd(y, x%y); }

struct MAT
{
	int Val[2][2];
	MAT(int a, int b, int c, int d)
	{
		Val[0][0] = a; Val[0][1] = b;
		Val[1][0] = c; Val[1][1] = d;
	}
	MAT operator*(MAT A)
	{
		MAT result = MAT(0, 0, 0, 0);
		for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++)
			result.Val[i][j] = (result.Val[i][j] + 1ll * Val[i][k] * A.Val[k][j]) % MOD;
		return result;
	}
};
int main()
{
	cin >> A >> B; N = gcd(A, B);
	MAT base = MAT(1, 1, 1, 0);
	MAT result = MAT(1, 0, 0, 1);
	MAT power = base;
	while(N > 0)
	{
		if(N % 2 == 1) result = result * power;
		power = power * power;
		N /= 2;
	}
	printf("%d", result.Val[1][0]);
	return 0;
}