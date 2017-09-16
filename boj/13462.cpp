#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX_N = 1e6 + 10;

int N; char S[MAX_N], counter[999];
int main()
{
	scanf("%s", S); N = strlen(S);
	counter['R'] = 'S';
	counter['B'] = 'K';
	counter['L'] = 'H';
	for(int i=0; i<N; i++)
	{
		if(i+2<N && S[i] != S[i+1] && S[i+1] != S[i+2] && S[i+2] != S[i])
		{
			printf("C");
			i+=2;
		}
		else printf("%c", counter[S[i]]);
	}
	return 0;
}