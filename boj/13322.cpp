#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char S[101101];
int main()
{
	int N; scanf("%s", S); N = strlen(S);
	for(int i=0; i<N; i++) printf("%d\n", i);
	return 0;
}