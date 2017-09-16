#include <stdio.h>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int N; string S; map<string, int> M;
int main()
{
	int ans = 0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
	{
		cin >> S;
		if(M.count(S) == 0) M[S] = 0;
		M[S]++;
		if(M[S]-1 > i-M[S]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}