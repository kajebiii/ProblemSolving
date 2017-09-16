// =====================================================================================
//
//       Filename:  1592.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 00:37:50
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>

int gcd(int a, int b)
{
	return a==0?b:gcd(b%a, a);
}

int main()
{
	int N, M, L;
	scanf("%d%d%d", &N, &M, &L);
	printf("%d\n", (M-1) * N / gcd(N, L));
	return 0;
}
