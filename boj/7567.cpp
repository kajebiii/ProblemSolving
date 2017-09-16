// =====================================================================================
//
//       Filename:  7567.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:42:55
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
	string S; cin >> S;
	int Ans = 10 * S.length();
	for(int i=1; i<S.length(); i++)
		if(S[i-1] == S[i])
			Ans -= 5;
	cout << Ans;
	return 0;
}










