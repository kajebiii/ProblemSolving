// =====================================================================================
//
//       Filename:  5904.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/14/2016 00:44:30
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>

long long L[50];
int N;

void find(int n, int k)
{
	if(n == 0)
	{
		if(k == 1) printf("m");
		else printf("o");
		return;
	}
	if(k <= L[n-1])
		find(n-1, k);
	else if(k >= L[n] - L[n-1] + 1)
		find(n-1, k - L[n] + L[n-1]);
	else if(k == (L[n-1] + 1))
		printf("m");
	else
		printf("o");
	return;
}

int main()
{
	L[0] = 3;
	for(int i=1; i<=30; i++)
		L[i] = 2 * L[i-1] + i + 3;
	scanf("%d", &N);
	find(30, N);
	return 0;
}
