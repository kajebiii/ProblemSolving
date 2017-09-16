// =====================================================================================
//
//       Filename:  9455.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 17:56:11
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

int Map[222][222];

int main() {
	int T; cin >> T;
	for(; T--;)
	{
		int N, M; scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &Map[i][j]);
		int ans = 0;
		for(int j=0; j<M; j++)
		{
			int cnt = N-1;
			for(int i=N-1; i>=0; i--)
				if(Map[i][j] == 1)
				{
					ans += (cnt - i);
					cnt--;
				}
		}
		printf("%d\n", ans);
	}
	return 0;
}










