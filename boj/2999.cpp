// =====================================================================================
//
//       Filename:  2999.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/15/2016 18:26:58
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int L, N, M;
string S;

int main()
{
	cin >> S;
	L = S.length();

	for(int i=1; i*i<=L; i++)
		if(L % i == 0)
			N = i, M = L / i;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			printf("%c", S[i+j*N]);

	return 0;
}
