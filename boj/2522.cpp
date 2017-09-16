// =====================================================================================
//
//       Filename:  2522.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:15:54
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
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N-i; j++)
			cout << " ";
		for(int j=1; j<=i; j++)
			cout << "*";
		cout << endl;
	}
	for(int i=N-1; i>=1; i--)
	{
		for(int j=1; j<=N-i; j++)
			cout << " ";
		for(int j=1; j<=i; j++)
			cout << "*";
		cout << endl;
	}
	return 0;
}










