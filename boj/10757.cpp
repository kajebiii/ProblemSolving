// =====================================================================================
//
//       Filename:  10757.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 18:16:01
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

string A, B;
int X[11111], Y[11111];

int main() {
	cin >> A >> B;
	for(int i=0; i<A.length(); i++)
		X[i] = A[A.length() - 1 - i] - '0';
	for(int i=0; i<B.length(); i++)
		Y[i] = B[B.length() - 1 - i] - '0';
	for(int i=0; i<11110; i++)
		X[i] += Y[i], X[i+1] += X[i] / 10, X[i] %= 10;
	bool first = false;
	for(int i=11110; i>=0; i--)
	{
		if(X[i] != 0) first = true;
		if(first)
			printf("%d", X[i]);
	}
	return 0;
}










