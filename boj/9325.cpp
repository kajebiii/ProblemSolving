// =====================================================================================
//
//       Filename:  9325.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:51:42
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
	int T; cin >> T;
	for(; T--;)
	{
		int S, N; cin >> S >> N;
		long long result = S;
		for(; N--;)
		{
			int x, y; scanf("%d%d", &x, &y);
			result += 1ll * x * y;
		}
		cout << result << endl;
	}
	return 0;
}










