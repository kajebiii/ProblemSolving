#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int N, Cnt[3];

int main()
{
	scanf("%d", &N);

	for(int i=0; i<N; i++)
	{
		string S; cin >> S;
		if(S == "1/4") Cnt[0]++;
		else if(S == "1/2") Cnt[1]++;
		else Cnt[2]++;
	}
	int ans = Cnt[2];
	Cnt[0] -= Cnt[2]; Cnt[0] = max(Cnt[0], 0);
	ans += Cnt[1] / 2; Cnt[1] %= 2;
	ans += Cnt[1]; if(Cnt[1] == 1) Cnt[0] = max(0, Cnt[0] - 2);
	ans += (Cnt[0] + 3) / 4;

	printf("%d\n", ans);
	return 0;
}