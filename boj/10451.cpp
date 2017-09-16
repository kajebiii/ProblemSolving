// =====================================================================================
//
//       Filename:  10451.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 16:15:51
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

int N, Nr[1111], Chk[1111];
int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("%d", &N);
		for(int i=1; i<=N; i++) Chk[i] = 0;
		int ans = 0;
		for(int i=1; i<=N; i++)
			scanf("%d", &Nr[i]);
		for(int i=1; i<=N; i++)
		{
			if(Chk[i] == 1) continue;
			ans++;
			int now = i;
			while(Chk[now] == 0)
				Chk[now] = 1, now = Nr[now];
		}
		printf("%d\n", ans);
	}
	return 0;
}










