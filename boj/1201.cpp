#include <stdio.h>
#include <algorithm>

using namespace std;

int Cnt[555];
int main()
{
	int N, A, B; scanf("%d%d%d", &N, &A, &B);
	if(N > A*B || N < A+B-1) {puts("-1"); return 0;}
	//(N-B) -> (A-1) Group;
	Cnt[1] = B;
	for(int i=2; i<=A; i++) Cnt[i] = 1;
	int rest = N - B - A + 1;
	for(int i=2; i<=A; i++)
	{
		if(rest >= B-1) Cnt[i] = B, rest -= (B-1);
		else Cnt[i] += rest, rest = 0;
	}

	int now = 0;
	for(int i=1; i<=A; i++)
	{
		now += Cnt[i];
		for(int j=0; j<Cnt[i]; j++)
			printf("%d ", now - j);
	}
	return 0;
}