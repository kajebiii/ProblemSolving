// =====================================================================================
//
//       Filename:  3028.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 23:57:46
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

int A[3];

int main() {
	string S; cin >> S;
	A[0] = 1;
	for(char x : S)
	{
		if(x == 'A') swap(A[0], A[1]);
		else if(x == 'B') swap(A[1], A[2]);
		else swap(A[0], A[2]);
	}
	for(int i=0; i<3; i++)
		if(A[i]) cout << i+1;
	return 0;
}










