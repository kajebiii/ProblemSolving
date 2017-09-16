// =====================================================================================
//
//       Filename:  10801.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:41:52
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
	int A[10];
	for(int i=0; i<10; i++) cin >> A[i];
	int X = 0, Y = 0;
	for(int x, i=0; i<10; i++)
	{
		cin >> x;
		if(A[i] > x) X++;
		else if(A[i] < x) Y++;
	}
	if(X > Y) puts("A");
	else if(X < Y) puts("B");
	else puts("D");
	return 0;
}










