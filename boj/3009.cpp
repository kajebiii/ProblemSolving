// =====================================================================================
//
//       Filename:  3009.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 13:03:18
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int A[2][3];
	for(int i=0; i<3; i++) for(int j=0; j<2; j++) cin >> A[j][i];
	for(int i=0; i<2; i++) 
	{
		sort(A[i], A[i] + 3);
		if(A[i][0] == A[i][1]) 
			cout << A[i][2] << " ";
		else
			cout << A[i][0] << " ";
	}
	return 0;
}










