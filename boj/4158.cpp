// =====================================================================================
//
//       Filename:  4158.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/13/2016 23:05:04
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> A, B;
int N, M;

int main()
{
	while(scanf("%d%d", &N, &M))
	{
		if(!N && !M) break;
		for(int x, i=0; i<N; i++, scanf("%d", &x), A.push_back(x));
		for(int x, i=0; i<M; i++, scanf("%d", &x), B.push_back(x));
		int result = 0, j = 0;
		for(int i=0; i<N; i++)
			while(j < M && B[j] <= A[i])
				result += (B[j++] == A[i]);
		printf("%d\n", result);
		A.clear(); B.clear();
		A.shrink_to_fit();
		B.shrink_to_fit();
	}	

	return 0;
}






