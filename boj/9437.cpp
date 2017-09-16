// =====================================================================================
//
//       Filename:  9437.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 19:45:10
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <iostream>

using namespace std;

int main()
{
	int N, M;
	while(1)
	{
		scanf("%d", &N); if(N == 0) break;
		scanf("%d", &M);

		for(int i=1; i<=N/2; i+=2)
		{
			int A[4];
			A[0] = i; A[1] = i+1;
			A[2] = N-i; A[3] = N-i+1;

			for(int j=0; j<4; j++) if(A[j] == M) for(int k=0; k<4; k++) if(j != k) printf("%d ", A[k]);
		}
		printf("\n");
	}

	return 0;
}
