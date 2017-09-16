// =====================================================================================
//
//       Filename:  1700.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 00:07:29
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>

const int MAX_N = 999;

int N, K;
int Nr[MAX_N];
int Chk[MAX_N], Cnt;

int main()
{
	scanf("%d%d", &K, &N);

	for(int i=1; i<=N; i++)
		scanf("%d", &Nr[i]);

	int result = 0;
	for(int i=1; i<=N; i++)
	{
		if(Chk[Nr[i]] == 1) continue;
		
		if(Cnt < K)
		{
			Chk[Nr[i]] = 1;
			Cnt++;
			continue;
		}

		int maxNr = -1, maxIdx = -1;
		for(int j=1; j<=N; j++)
		{
			if(Chk[j] == 0) continue;
			int nowIdx = N+1;
			for(int k=i+1; k<=N; k++)
				if(Nr[k] == j)
				{
					nowIdx = k;
					break;
				}
			if(maxIdx < nowIdx)
				maxIdx = nowIdx, maxNr = j;
		}

		Chk[maxNr] = 0;
		Chk[Nr[i]] = 1;

		result++;
	}
	printf("%d\n", result);
	return 0;
}












