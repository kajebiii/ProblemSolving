#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX_N = 2e3 + 100;

char S[MAX_N]; int N, Dy[MAX_N];
bool isP[MAX_N][MAX_N];

void findP(int a, int b)
{
	while(a >= 1 && b <= N && S[a] == S[b])
	{
		isP[a][b] = true;
		a--; b++;
	}
}
int main()
{
	scanf("%s", S+1); N = strlen(S+1);
	for(int i=1; i<=N; i++) for(int j=i; j<=N; j++) isP[i][j] = false;
	for(int i=0; i<=N; i++) Dy[i] = 0x7ffffff;
	for(int i=1; i<=N; i++) findP(i, i);
	for(int i=2; i<=N; i++) findP(i-1, i);
	Dy[0] = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=i; j++)
			if(isP[j][i])
				Dy[i] = min(Dy[i], Dy[j-1] + 1);
	}
	printf("%d\n", Dy[N]);
	return 0;
}