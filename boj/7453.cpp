#include <stdio.h>
#include <algorithm>

using namespace std;

int N, Array[4][4444];
int Sum[2][16000001];
int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) for(int j=0; j<4; j++) scanf("%d", &Array[j][i]);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) for(int k=0; k<2; k++)
		Sum[k][i*N+j] = Array[k*2][i] + Array[k*2+1][j];
	for(int k=0; k<2; k++) sort(Sum[k], Sum[k] + N*N);
	
	int lo = N*N, up = N*N;
	long long ans = 0;
	for(int i=0; i<N*N; i++)
	{
		while(lo != 0 && Sum[1][lo-1] >= -Sum[0][i]) lo--;
		while(up != 0 && Sum[1][up-1] >  -Sum[0][i]) up--;
		ans += (up - lo);
	}
	printf("%lld\n", ans);
	return 0;
}