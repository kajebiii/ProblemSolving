#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 22;
typedef long long ll;

int N, M;

ll ggcd(ll a, ll b) {return b==0?a:ggcd(b, a%b);}
ll Dy[MAX_N][MAX_N], F[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for(int i=0; i<=N; i++) F[i][i] = i; F[0][0] = 1;
	for(int i=0; i<=N; i++) for(int j=i+1; j<=N; j++) F[i][j] = F[i][j-1] * j;
	for(int i=0; i<=N; i++) for(int j=0; j<i; j++) F[i][j] = 1;
	for(int i=0; i<=N; i++) for(int j=i; j<=N; j++) Dy[i][j] = F[0][i];
	for(int i=1; i<=N; i++) Dy[i][0] = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<i; j++) {
		ll sum = 0;
		for(int k=0; k<i; k++) sum += Dy[k][j-1] * F[k+1][i-1];
		Dy[i][j] = sum;
		ll gcd = ggcd(Dy[i][j], F[1][i]);
	}
	ll gcd = ggcd(Dy[N][M], F[1][N]);
	printf("%lld/%lld\n", Dy[N][M]/gcd, F[1][N]/gcd);
	return 0;
}