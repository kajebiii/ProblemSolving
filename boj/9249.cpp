// =====================================================================================
//
//       Filename:  9249.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/30/2016 13:03:49
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
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 4e5 + 100;

int N, M;
char S[MAX_N];

int SA[MAX_N], LCP[MAX_N];
void getSAnLCP()
{
	int m = 128;
	vector<int> cnt(max(N, m)+1, 0), x(N+1, 0), y(N+1, 0);
	for(int i=1; i<=N; i++) cnt[x[i] = S[i]]++;
	for(int i=1; i<=m; i++) cnt[i] += cnt[i-1];
	for(int i=N; i>=1; i--) SA[cnt[x[i]]--] = i;
	for(int len=1, p=0; p<N; m=p, len <<= 1)
	{
		p=0;
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
			int al = a + len, bl = b + len;
			x[b] = (al<=N && bl<=N && y[a]==y[b] && y[al]==y[bl])?p:++p;
		}
	}
	vector<int> rank(N+1, 0);
	for(int i=1; i<=N; i++) rank[SA[i]] = i;
	for(int i=1, k=0, j; i<=N; LCP[rank[i++]] = k)
		for(k?k--:0, j=SA[rank[i]-1]; S[i+k] == S[j+k]; k++);
}

int main() {
	scanf("%s", S+1); N = (int)strlen(S+1);
	S[N+1] = '#';
	scanf("%s", S+N+2);
	M = (int)strlen(S+N+2);
	N = N + 1 + M;

	getSAnLCP();
	int nowMin = INF, ans = 0, index = 0;
	for(int i=1; i<=N; i++)
	{
		if(SA[i] <= N-M-1)
			nowMin = LCP[i+1];
		else
		{
			if(nowMin == INF) continue;
			ans = max(ans, nowMin);
			if(ans == nowMin) index = SA[i];
			nowMin = min(nowMin, LCP[i+1]);
		}
	}
	nowMin = INF;
	for(int i=N; i>=1; i--)
	{
		if(SA[i] <= N-M-1)
			nowMin = LCP[i];
		else
		{
			if(nowMin == INF) continue;
			ans = max(ans, nowMin);
			if(ans == nowMin) index = SA[i];
			nowMin = min(nowMin, LCP[i]);
		}
	}
	cout << ans << endl;
	for(int i=index; i<index+ans; i++) printf("%c", S[i]);
	return 0;
}










