#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int Cnt[4];

int main()
{
	vector<int> P = {2, 3, 5, 7};
	int T; scanf("%d", &T);
	while(T--)
	{
		int N; scanf("%d", &N);
		for(int i=0; i<4; i++) Cnt[i] = 0;
		for(int i=0; i<4; i++)
			while(N % P[i] == 0)
			{
				N /= P[i];
				Cnt[i]++;
			}
		if(N != 1) {puts("-1"); continue;}
		Cnt[0] += 2; Cnt[1] += 1;
		printf("%d\n", max(1, min(Cnt[0]/3 + Cnt[1]/2, (Cnt[0]-1)/3 + (Cnt[1]-1)/2 + 1) + Cnt[2] + Cnt[3]));
	}
	return 0;
}