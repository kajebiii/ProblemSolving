// =====================================================================================
//
//       Filename:  2805.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 16:39:26
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

long long Nr[1111111];
int main() {
	int N, M; cin >> N >> M;
	for(int i=0; i<N; i++) scanf("%lld", &Nr[i]);
	
	int s = 0, e = INF / 2, m;
	int ans = 0;
	while(s <= e)
	{
		 m = (s + e) / 2;
		 long long now = 0;
		 for(int i=0; i<N; i++)
			 if(Nr[i] > m)
				 now += Nr[i] - m;
		 if(now >= M)
		 {
			 ans = m;
			 s = m + 1;
		 }
		 else
			 e = m - 1;
	}
	printf("%d\n", ans);
	return 0;
}










