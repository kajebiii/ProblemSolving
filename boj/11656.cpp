// =====================================================================================
//
//       Filename:  11656.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 16:15:38
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
const int MAX_N = 1e3 + 100;

int N, SA[MAX_N];
char S[MAX_N];

int main() {
	scanf("%s", S+1);
	N = (int)strlen(S+1);

	int m = 26;
	vector<int> cnt(max(N,m)+1, 0), x(N+1, 0), y(N+1, 0);
	for(int i=1; i<=N; i++) cnt[x[i] = S[i] - 'a' + 1]++;
	for(int i=1; i<=m; i++) cnt[i] += cnt[i-1];
	for(int i=N; i>=1; i--) SA[cnt[x[i]]--] = i;
	for(int len = 1, p=1; p<N; len <<=1, m=p)
	{
		p = 0;
		for(int i=N-len+1; i<=N; i++) y[++p] = i;
		for(int i=1; i<=N; i++) if(SA[i] > len) y[++p] = SA[i] - len;
		for(int i=1; i<=m; i++) cnt[i] = 0;
		for(int i=1; i<=N; i++) cnt[x[y[i]]]++;
		for(int i=1; i<=m; i++) cnt[i] += cnt[i-1];
		for(int i=N; i>=1; i--) SA[cnt[x[y[i]]]--] = y[i];
		swap(x, y); p = 1; x[SA[1]] = 1;
		for(int i=1; i<N; i++)
		{
			int a = SA[i], b = SA[i+1];
			int al = a+len, bl = b+len;
			x[b] = (al<=N && bl<=N && y[a]==y[b] && y[al]==y[bl])?p:++p;
		}
	}
	for(int i=1; i<=N; i++)
		printf("%s\n", S+SA[i]);
	return 0;
}










