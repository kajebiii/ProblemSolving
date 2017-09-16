// =====================================================================================
//
//       Filename:  2670.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 16:38:45
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
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int N;
double Dy[11111];
int main() {
	cin >> N;
	Dy[0] = 1;
	double ans = 0;
	for(int i=1; i<=N; i++)
	{
		double x; scanf("%lf", &x);
		Dy[i] = max(x, Dy[i-1]*x);
		ans = max(ans, Dy[i]);
	}
	printf("%.3lf", ans);
	return 0;
}










