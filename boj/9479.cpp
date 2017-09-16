#include <stdio.h>
#include <string.h>

using namespace std;

const int MAX_N = 1e3 + 10;
char C[MAX_N]; int N;
int Chk[MAX_N];
int main()
{
	while(1)
	{
		scanf("%s", C);
		N = strlen(C);
		for(int i=0; i<N; i++) Chk[i] = 0;
		if(N == 1 && C[0] == '0') break;
		
		bool first = true;
		for(int i=1; i<N; i++)
		{
			if(Chk[i] == (C[i] - '0')) continue;
			if(!first) printf(" "); first = false;
			printf("%d", i);
			for(int j=0; j<N; j+=i) Chk[j] = 1 - Chk[j];
		}
		printf("\n");
	}
	return 0;
}