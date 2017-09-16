// =====================================================================================
//
//       Filename:  10808.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:31:59
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

int D[300];
int main() {
	string S; cin >> S;
	for(auto x : S)
		D[x]++;
	for(int x = 'a'; x <= 'z'; x++)
		printf("%d ", D[x]);
	return 0;
}










