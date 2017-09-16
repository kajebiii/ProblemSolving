#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 20;
int N, M, L, Nr[MAX_N];

int main()
{
	scanf("%d%d%d", &N, &M, &L);
	Nr[0] = 0; Nr[N+1] = L;
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N+2);

	int ans = -1;
	for(int l=1, r=L; l<r;)
	{
		int m = (l+r) >> 1;
		int use = 0;
		for(int i=0; i<=N; i++)
			use += (Nr[i+1] - Nr[i] - 1) / m; 
		if(use <= M) r = m;
		else l = m+1;
		ans = l;
	}
	printf("%d\n", ans);
	return 0;
}