// =====================================================================================
//
//       Filename:  6523.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 12:10:01
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

map<int, int> M;

int main() {
	int N, A, B;
	while(1)
	{
		scanf("%d", &N); if(N == 0) break;
		scanf("%d%d", &A, &B);
		M.clear();
		int now = 0;
		int cnt = 0;
		while(M.count(now) == 0)
		{
			M[now] = cnt;
			cnt++;
			now = 1ll * now * now % N * A % N + B; now %= N;
		}
		printf("%d\n", N - cnt + M[now]);
	}
	return 0;
}










