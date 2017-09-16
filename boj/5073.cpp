// =====================================================================================
//
//       Filename:  5073.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/13/2016 23:30:36
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

int A[3];
int main()
{
	while(scanf("%d%d%d", &A[0], &A[1], &A[2]))
	{
		if(A[2] == 0) break;
		sort(A, A+3);
		if(A[0] == A[2])
			printf("Equilateral\n");
		else if(A[0] + A[1] <= A[2])
			printf("Invalid\n");
		else if(A[0] == A[1] || A[1] == A[2])
			printf("Isosceles\n");
		else 
			printf("Scalene\n");
	}
	return 0;
}
