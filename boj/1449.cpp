#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 100;

int N, L, Nr[MAX_N];

int main()
{
	scanf("%d%d", &N, &L);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N);

	int ans = 0, left = -1;
	for(int i=0; i<N; i++)
	{
		if(i == 0 || left + L - 1 < Nr[i])
		{
			ans++;
			left = Nr[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}