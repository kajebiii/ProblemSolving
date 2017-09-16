// =====================================================================================
//
//       Filename:  2587.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 23:48:40
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int A[5];
	for(int i=0; i<5; i++)
		cin >> A[i];
	sort(A, A+5);
	int sum = accumulate(A, A+5, 0);
	int mode = A[2];
	cout << sum / 5 << endl << mode << endl;
	return 0;
}










