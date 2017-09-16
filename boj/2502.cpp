// =====================================================================================
//
//       Filename:  2502.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:44:05
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

int X[33], Y[33];
int main() {
	int A, B; cin >> A >> B;
	X[1] = Y[2] = 1;
	for(int i=3; i<=30; i++)
		X[i] = X[i-1] + X[i-2], Y[i] = Y[i-1] + Y[i-2];
	for(int i=1; i<=100000; i++)
	{
		int c = B - i * X[A];
		if(c < 0) break;
		if(c % Y[A] == 0)
		{
			printf("%d\n%d\n", i, c/Y[A]);
			break;
		}
	}
	return 0;
}










