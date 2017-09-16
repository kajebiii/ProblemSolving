// =====================================================================================
//
//       Filename:  9358.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 03:01:45
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>

int N, Nr[111];

int main()
{
	int T; scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
			scanf("%d", Nr+i);

		while(N > 2)
		{
			for(int i=1; i<=(N+1)/2; i++)
				Nr[i] += Nr[N+1-i];
			N = (N+1)/2;
		}
		printf("Case #%d: ", t);
		if(Nr[1] > Nr[2])
			printf("Alice\n");
		else
			printf("Bob\n");
	}
}
