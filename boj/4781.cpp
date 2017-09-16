// =====================================================================================
//
//       Filename:  4781.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/15/2016 18:15:27
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e3 + 50;
const int MAX_M = 1e4 + 100;

int N, M;
int Dy[MAX_M];

int main()
{
	int Ma, Mb;
	while(scanf("%d %d.%d", &N, &Ma, &Mb))
	{
		if(N == 0) break;
		M = Ma * 100 + Mb;
		
		for(int i=0; i<MAX_M; i++)
			Dy[i] = -1;

		Dy[0] = 0;
		
		int nowC, nowMa, nowMb, nowM;
		int result = 0;
		for(int i; N--; )
			for(i=0, scanf("%d %d.%d", &nowC, &nowMa, &nowMb); i<=M; i++)
			{
				nowM = nowMa * 100 + nowMb;
				if(Dy[i] < 0) continue;
				if(i + nowM > M) continue;
				
				Dy[i + nowM] = max(Dy[i + nowM], Dy[i] + nowC);
				result = max(result, Dy[i + nowM]);
			}

		printf("%d\n", result);
	}
	return 0;
}










