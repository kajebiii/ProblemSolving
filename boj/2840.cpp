#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e1 + 10;

int N, K;
bool impos = false;
char S[MAX_N];

int main()
{
	scanf("%d%d", &N, &K);
	int now = 0;
	for(int i=0; i<N; i++) S[i] = '?';
	for(int _=0; _<K; _++)
	{
		int x; char k;
		scanf("%d %c", &x, &k);
		now = (now + (N*N*N-x) ) % N;
		if(S[now] == '?') S[now] = k;
		else if(S[now] != k)
		{
			impos = true;
			break;
		}
	}
	for(int i=0; i<N; i++) for(int j=i+1; j<N; j++)
		if(S[i] != '?' && S[i] == S[j]) 
			impos = true;
	if(impos) puts("!");
	else
	{
		for(int i=0; i<N; i++) printf("%c", S[(now+i)%N]);
	}
	return 0;
}