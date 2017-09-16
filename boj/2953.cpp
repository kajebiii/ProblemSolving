// =====================================================================================
//
//       Filename:  2953.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:07:28
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
#include <numeric>
#include <string.h>
#include <string>

using namespace std;

int main() {
	int A[5];
	for(int i=0; i<5; i++)
	{
		int sum = 0;
		for(int j=0; j<4; j++)
		{
			int x; cin >> x;
			sum += x;
		}
		A[i] = sum;
	}
	int index = max_element(A, A+5) - A;
	printf("%d %d\n", index+1, A[index]);
	return 0;
}










