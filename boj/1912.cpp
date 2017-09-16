// =====================================================================================
//
//       Filename:  1912.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 20:22:22
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

const int MAX_N = 1e5 + 10;

int N, Nr[MAX_N];

int main() {
	cin >> N;
	int result = -0x7fffffff;
	for(int i=1; i<=N; i++)
	{
		int x; scanf("%d", &x);
		Nr[i] = max(x, Nr[i-1] + x);
		result = max(result, Nr[i]);
	}
	cout << result;
	return 0;
}










