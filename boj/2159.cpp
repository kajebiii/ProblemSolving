// =====================================================================================
//
//       Filename:  2159.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/15/2016 19:07:52
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int MAX_N = 1e5 + 10;
const long long INF = 1ll * 0x7fffffff * 0x7fffffff;

int N, Nr[MAX_N][2];
long long Dy[MAX_N][5];
int C[2][5] = {{0, 1, 0, -1, 0}, {0, 0, 1, 0, -1}};

int main()
{
	scanf("%d", &N);
	scanf("%d%d", &Nr[0][0], &Nr[0][1]);

	for(int i=0; i<=N; i++)
		for(int j=0; j<5; j++)
			Dy[i][j] = INF;
	Dy[0][0] = 0;
	for(int i=1; i<=N; i++)
	{
		scanf("%d%d", &Nr[i][0], &Nr[i][1]);
		for(int ki=0; ki<5; ki++)
			for(int kj=0; kj<5; kj++)
				if(Dy[i-1][ki] != INF)
				   Dy[i][kj] = min(Dy[i][kj], Dy[i-1][ki] + abs(Nr[i-1][0] + C[0][ki] - Nr[i][0] - C[0][kj]) 
						   								  + abs(Nr[i-1][1] + C[1][ki] - Nr[i][1] - C[1][kj]));
		if(i == N)
		{
			long long result = INF;
			for(int j=0; j<5; j++)
				result = min(result, Dy[N][j]);
			printf("%lld\n", result);
		}
	}

	return 0;
}









