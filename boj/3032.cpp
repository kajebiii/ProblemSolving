#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e2 + 10;

int N, Nr[MAX_N * 2], Dy[MAX_N * 2][MAX_N * 2];
int getDy(int a, int b)
{
	int &val = Dy[a][b];
	if(val != -1) return val;
	if(a == b) {val = (Nr[a]%2==1); return val;}
	if(a > b) {val = 0; return val;}
	val = max(val, (Nr[a]%2==1) + min(getDy(a+1,b-1), getDy(a+2,b)));
	val = max(val, (Nr[b]%2==1) + min(getDy(a+1,b-1), getDy(a,b-2)));
	return val;
}
int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]), Nr[i+N] = Nr[i];
	for(int i=1; i<=N*2; i++) for(int j=i; j<=N*2; j++) Dy[i][j] = -1;
	for(int i=1; i<=N; i++) getDy(i+1, i+N-1);
	int allOdd = 0, ans = 0;
	for(int i=1; i<=N; i++) allOdd += (Nr[i] % 2);
	for(int i=1; i<=N; i++) if(allOdd - getDy(i+1, i+N-1) > getDy(i+1, i+N-1)) ans++;
	printf("%d\n", ans);
	return 0;
}