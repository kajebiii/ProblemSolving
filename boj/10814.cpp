// =====================================================================================
//
//       Filename:  10814.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/29/2016 18:10:57
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
const int MAX_N = 1e5 + 100;

pair<pi, string> Nr[MAX_N]; 
int N; char C[999];

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
	{
		scanf("%d", &Nr[i].fi.fi);
		Nr[i].fi.se = i;
		scanf("%s", C);
		Nr[i].se = string(C);
	}
	sort(Nr, Nr+N);
	for(int i=0; i<N; i++)
	{
		printf("%d ", Nr[i].fi.fi);
		const char *c = (Nr[i].se).c_str();
		printf("%s\n", c);
	}
	return 0;
}










