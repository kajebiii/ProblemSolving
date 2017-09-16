// =====================================================================================
//
//       Filename:  2822.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 15:01:38
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

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int main() {
	int A[8], B[8];
	for(int i=0; i<8; i++)
	{
		cin >> A[i];
		B[i] = A[i];
	}
	sort(A, A+8);
	cout << accumulate(A+3, A+8, 0) << endl;
	for(int i=0; i<8; i++)
		for(int j=3; j<8; j++)
			if(B[i] == A[j])
				cout << i+1 << " ";
	return 0;
}










