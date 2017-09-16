// =====================================================================================
//
//       Filename:  2003.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 15:15:18
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

int N, M;
set<int> S;

int main() {
	cin >> N; cin >> M; for(int s=0, x, i=1; i<=N; i++) scanf("%d", &x), S.insert(s+=x); S.insert(0);
	int cnt = 0; for(auto x : S) cnt += S.count(x + M); cout << cnt;
	return 0;
}










