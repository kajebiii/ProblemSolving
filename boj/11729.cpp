// =====================================================================================
//
//       Filename:  11729.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 13:14:40
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

void printAns(int n, int a, int b)
{
	if(n == 0) return;
	int c = (1 + 2 + 3) - a - b;
	printAns(n-1, a, c);
	printf("%d %d\n", a, b);
	printAns(n-1, c, b);
}

int main() {
	int N; cin >> N;
	cout << (1 << N) - 1 << endl;
	printAns(N, 1, 3);
	return 0;
}










