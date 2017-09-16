// =====================================================================================
//
//       Filename:  10174.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/14/2016 03:15:23
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <string.h>

int N;
char S[10000];

int main()
{
	scanf("%d\n", &N);

	for(; N--; )
	{
		fgets(S, 10000, stdin);
		int n = (int)strlen(S) - 1;
		for(int i=0; i<n; i++)
			if(S[i] >= 'A' && S[i] <= 'Z')
				S[i] += ('a' - 'A');

		int flag = true;
		for(int i=0; i<n; i++)
			if(S[i] != S[n-1-i])
				flag = false;
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}













