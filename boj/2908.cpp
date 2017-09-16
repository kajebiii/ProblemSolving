// =====================================================================================
//
//       Filename:  2908.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 21:48:31
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
	int A[2] = {0, 0};
	for(int j=0; j<2; j++)
		for(int p=1, i=0; i<3; i++, p *= 10)
		{
			int x; scanf("%1d", &x);
			A[j] += x * p;
		}
	cout << max(A[0], A[1]);
	
	return 0;
}










