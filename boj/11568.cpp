// =====================================================================================
//
//       Filename:  11568.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 17:36:13
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

const int MAX_N = 1000;

int A[MAX_N];

int main()
{
	int N; scanf("%d", &N);
	int cnt = 0;

	for(; N--; )
	{
		int x; scanf("%d", &x);
		int index = (int)(lower_bound(A+1, A+1+cnt, x) - A);
		if(index > cnt) 
			A[++cnt] = x;
		else
		    A[index] = x;	
	}

	printf("%d\n", cnt);

	return 0;
}
