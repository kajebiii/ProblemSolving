#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_L = 531441;

char S[MAX_L + 100];

int main()
{
	for(int i=0; i<MAX_L; i++)
	{
		int now = i;
		bool isOne = false;
		while(now)
		{
			if(now%3 == 1) isOne = true;
			now /= 3;
		}
		if(isOne) S[i] = ' ';
		else S[i] = '-';
	}
	int N;
	while(scanf("%d", &N) == 1)
	{
		int now = 1;
		for(int i=0; i<N; i++) now *= 3;
		printf("%s\n", S+MAX_L-now);
	}
	return 0;
}