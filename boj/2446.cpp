// =====================================================================================
//
//       Filename:  2446.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:33:15
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
	int N; cin >> N;
	for(int i=N; i>=1; i--)
	{
		for(int j=N; j>i; j--) cout << " ";
		for(int j=1; j<2*i; j++) cout << "*";
		cout << endl;
	}
	for(int i=2; i<=N; i++)
	{
		for(int j=N; j>i; j--) cout << " ";
		for(int j=1; j<2*i; j++) cout << "*";
		cout << endl;
	}
	return 0;
}










