// =====================================================================================
//
//       Filename:  2309.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 20:59:30
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
	int A[9];
	for(int i=0; i<9; i++)
		cin >> A[i];
	int sum = accumulate(A, A+9, 0);
	for(int i=0; i<9; i++)
		for(int j=i+1; j<9; j++)
			if((sum - A[i] - A[j]) == 100)
				A[i] = A[j] = 101;
	sort(A, A+9);
	for(int i=0; i<7; i++)
		cout << A[i] << endl;
	return 0;
}










