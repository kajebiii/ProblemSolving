#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int MAX_N = 5e2 + 10;

int N, M, K, X;
char S[MAX_N];
char W[MAX_N][MAX_N];

int main()
{
	scanf("%d%d%d%d", &N, &M, &K, &X);
	scanf("%s", S);
	for(int i=0; i<M; i++) scanf("%s", W[i]);
	for(int i=0; i<M; i++) sort(W[i], W[i]+K);
	X = X-1;
	int j = M-1;
	for(int i=N-1; i>=0; i--)
	{
		if(S[i] == '#')
		{
			int now = X % K;
			X /= K;
			S[i] = W[j][now];
			j--;
		}
	}
	printf("%s", S);
	return 0;
}