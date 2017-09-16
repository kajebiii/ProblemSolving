// ====================================================================================
//
//       Filename:  1339.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/15/2016 18:35:43
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_N = 99;

int N, Cnt;
string S[MAX_N];
char List[MAX_N * 10];
int Change[200];

int main()
{
	scanf("%d", &N);
	
	for(int i=0; i<N; i++)
	{
		cin >> S[i];
		for(auto x : S[i])
			List[Cnt++] = x;
	}
	
	sort(List, List+Cnt);
	unique(List, List+Cnt);


	int nr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int result = 0;
	do
	{
		for(int i=0; i<10; i++)
			Change[List[i]] = nr[i];
		int nowNr = 0;
		for(int i=0; i<N; i++)
		{
			int l = S[i].length();
			int nr = 0;
			for(auto x : S[i])
				nr *= 10, nr += Change[x];
			nowNr += nr;
		}

		result = max(result, nowNr);
	}while(next_permutation(nr, nr+10));

	printf("%d\n", result);

	return 0;
}











