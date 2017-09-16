// =====================================================================================
//
//       Filename:  1546.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:35:31
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int N, sum = 0, mx = 0; cin >> N;
	for(int i=0, x; i<N; i++)
		cin >> x, sum += x, mx = max(mx, x);
	printf("%.2lf", (double)sum * 100 / mx / N);
	return 0;
}










