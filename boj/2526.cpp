// =====================================================================================
//
//       Filename:  2526.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 14:54:09
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

int cnt[9999];

int main() {
	int N, n, K; cin >> N >> K;
	int now = 0; n = N;
	while(cnt[n] == 0)
	{
		cnt[n] = ++now;
		n *= N;
		n %= K;
	}
	cout << now - cnt[n] + 1;
	return 0;
}










