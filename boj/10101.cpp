// =====================================================================================
//
//       Filename:  10101.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 17:24:56
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
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

int main() {
	int A[3]; for(int i=0; i<3; i++) cin >> A[i];
	sort(A, A+3);
	int sum = accumulate(A, A+3, 0);
	bool B[2] = {A[0] == A[1], A[1] == A[2]};
	if(sum != 180) 
		puts("Error");
	else if(B[0] && B[1])
		puts("Equilateral");
	else if(B[0] || B[1])
		puts("Isosceles");
	else
		puts("Scalene");
	return 0;
}










