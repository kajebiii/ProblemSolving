// =====================================================================================
//
//       Filename:  2750.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:12:07
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

int Nr[1111];

int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++)
		cin >> Nr[i];
	sort(Nr, Nr+N);
	for(int i=0; i<N; i++)
		cout << Nr[i] << endl;
	return 0;
}










