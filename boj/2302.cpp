// =====================================================================================
//
//       Filename:  2302.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 14:44:22
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

int V[55], Dy[55];
int main() {
	int N, M; cin >> N >> M;
	for(int i=1; i<=M; i++) scanf("%d", &V[i]);
	V[M+1] = N+1;
	Dy[0] = Dy[1] = 1;
	for(int i=2; i<=N; i++)
		Dy[i] = Dy[i-1] + Dy[i-2];
	int ans = 1;
	for(int i=1; i<=M+1; i++)
		ans *= Dy[(V[i] - V[i-1] - 1)];
	cout << ans;
	return 0;
}










