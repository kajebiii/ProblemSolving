#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int MAX_R = 55;

int R, N;
map<char, int> Mp;
char L[MAX_R], Nr[MAX_R][MAX_R];
int main()
{
	Mp['S'] = 0; Mp['P'] = 1; Mp['R'] = 2;
	scanf("%d", &R);
	scanf("%s", L);
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s", Nr[i]);

	int ans = 0, bigAns = 0;
	for(int r=0; r<R; r++)
	{
		int cnt[3] = {0, };
		for(int i=0; i<N; i++) cnt[Mp[Nr[i][r]]]++;
		int now = Mp[L[r]];
		int w = (now + 1) % 3, s = now, l = (now + 2) % 3;
		ans += cnt[w] * 2 + cnt[s];

		int bigNow = 0;
		for(now=0; now<3; now++)
		{
			int w = (now + 1) % 3, s = now, l = (now + 2) % 3;
			bigNow = max(bigNow, cnt[w]*2 + cnt[s]);
		}
		bigAns += bigNow;
	}
	printf("%d\n%d\n", ans, bigAns);
	return 0;
}