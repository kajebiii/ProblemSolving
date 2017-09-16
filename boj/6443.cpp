#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

int main()
{
	int N; scanf("%d", &N);
	char temp[10000];
	for(int i=0; i<N; i++)
	{
		scanf("%s", temp);
		string S = temp;
		sort(S.begin(), S.end());
		do
		{
			printf("%s\n", S.c_str());
		}while(next_permutation(S.begin(), S.end()));
	}
	return 0;
}