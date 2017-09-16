#include <stdio.h>
#include <algorithm>

using namespace std;

int C[26];

int main()
{
	int T; scanf("%d", &T); scanf(" ");
	while(T--)
	{
		char getIn[999]; 
		fgets(getIn, 999, stdin);
		for(int i=0; i<26; i++) C[i] = 0;
		for(int i=0; getIn[i]; i++) if(getIn[i] >= 'a' && getIn[i] <= 'z')
			C[getIn[i]-'a']++;

		int maxV = -1, cnt = 0, maxIx = -1;
		for(int i=0; i<26; i++)
			if(maxV < C[i])
			{
				maxV = C[i];
				cnt = 1;
				maxIx = i;
			}
			else if(maxV == C[i])
				cnt++;
		if(cnt > 1) puts("?");
		else printf("%c\n", 'a'+maxIx);
	}
	return 0;
}