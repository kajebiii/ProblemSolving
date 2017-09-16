#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 200;

int N, Nr[MAX_N], Dy[MAX_N];
int D[MAX_N];
int main()
{
	scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	int j=1;
	for(int i=1; i<=N; i=j)
	{
		while(j <= N && Nr[i] == Nr[j]) j++;
		while(j+1 <= N && Nr[i] < Nr[j] && Nr[j] <= Nr[j+1]) j++;
		while(j+1 <= N && Nr[i] > Nr[j] && Nr[j] >= Nr[j+1]) j++;
		Dy[j] = max(Dy[j], Dy[i] + abs(Nr[j] - Nr[i+1]) );
		Dy[j] = max(Dy[j], Dy[i-1] + abs(Nr[j] - Nr[i]));
		if(j-i >= 2)
			Dy[j-1] = max(Dy[j-1], Dy[i] + abs(Nr[j-1] - Nr[i+1]));
		Dy[j-1] = max(Dy[j-1], Dy[i-1] + abs(Nr[j-1] - Nr[i]));
	}
	int Ans = 0;
	for(int i=1; i<=N; i++) Ans = max(Ans, Dy[i]);
	printf("%d\n", Ans);
	return 0;
}