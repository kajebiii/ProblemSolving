// =====================================================================================
//
//       Filename:  2577.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:14:18
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
	int A, B, C; cin >> A >> B >> C;
	int D = A * B * C;
	int N[10] = {0};
	for(; D!=0; D/=10)
		N[D%10]++;
	for(int i=0; i<10; i++)
		cout << N[i] << endl;
	return 0;
}










