// =====================================================================================
//
//       Filename:  5666.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/14/2016 00:38:22
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>

int H, P;

int main()
{
	while(scanf("%d%d", &H, &P) != EOF)
		printf("%.2lf\n", (double)H / P);
	return 0;
}
