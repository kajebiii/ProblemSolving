// =====================================================================================
//
//       Filename:  1915.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 20:16:42
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
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 1111;
int N, M, Nr[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%1d", &Nr[i][j]);
	for(int j=1; j<=M; j++) for(int i=1; i<=N; i++) if(Nr[i][j]) Nr[i][j] += Nr[i-1][j];

	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		stack<pi> S;
		int j=1;
		S.push(mp(0, 0));
		while(j <= M+1)
		{
			if(S.empty() || S.top().fi <= Nr[i][j])
				S.push(mp(Nr[i][j], j)), j++;
			else
			{
				int right = j-1;
				int height = S.top().fi;
				S.pop();
				int left = S.top().se + 1;
				int minL = min(height, right - left + 1);
				ans = max(ans, minL*minL);
			}
		}
	}
	cout << ans;
	return 0;
}










