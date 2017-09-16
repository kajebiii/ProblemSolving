// =====================================================================================
//
//       Filename:  1699.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 00:26:51
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

const int MAX_N = 1e5 + 30;

int Dy[MAX_N], N;

int main()
{
	scanf("%d", &N);

	for(int i=1, j; i<=N; i++)
		for(j=1, Dy[i] = N; j*j<=i; j++)
			Dy[i] = min(Dy[i], Dy[i - j*j] + 1);

	printf("%d\n", Dy[N]);
	return 0;
}
