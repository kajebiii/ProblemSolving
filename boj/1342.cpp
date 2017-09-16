#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	string S; cin >> S;
	int N = S.size();
	sort(S.begin(), S.end());

	int ans = 0;
	do
	{
		bool isGood = true;
		for(int i=1; i<N; i++) if(S[i-1] == S[i]) {isGood = false; break;}
		if(isGood) ans++;
	}
	while(next_permutation(S.begin(), S.end()));

	printf("%d\n", ans);
	return 0;
}