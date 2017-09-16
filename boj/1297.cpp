// =====================================================================================
//
//       Filename:  1297.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/29/2016 18:05:51
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
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int get(int n, int a, int s)
{
	double r = (double)n * n / s * a * a;
	return (int)sqrt(r);
}
int main() {
	int N, A, B; cin >> N >> A >> B;
	printf("%d %d\n", get(N, A, A*A+B*B), get(N, B, A*A+B*B));
	return 0;
}










