// =====================================================================================
//
//       Filename:  4796.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 15:19:03
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int L, P, V;

int main()
{
	int t = 0;
	while(1)
	{
		scanf("%d%d%d", &L, &P, &V);
		if((L+P+V) == 0) break;
		printf("Case %d: %d\n", ++t, V/P*L + min(V%P, L));
	}
}
