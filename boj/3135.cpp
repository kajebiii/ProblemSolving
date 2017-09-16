// =====================================================================================
//
//       Filename:  3135.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 19:02:02
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
#include <stdlib.h>

using namespace std;

int main()
{
	int A, B; cin >> A >> B;
	int C = abs(A - B);
	int N; cin >> N;

	for(; N--;)
	{
		int x; cin >> x;
		C = min(C, abs(x-B)+1);
	}
	printf("%d\n", C);

	return 0;
}
