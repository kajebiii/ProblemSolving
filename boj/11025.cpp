// =====================================================================================
//
//       Filename:  11025.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 12:04:50
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

int main() {
	int N, K; cin >> N >> K;
	int r = 0;
	for(int i=2; i<=N; i++)
		r = (r + K) % i;
	cout << r + 1;
	return 0;
}










