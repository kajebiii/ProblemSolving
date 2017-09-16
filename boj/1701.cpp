// =====================================================================================
//
//       Filename:  1701.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 13:10:43
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
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 5e3 + 50;

int SA[MAX_N], LCP[MAX_N], N;
char S[MAX_N];
int main() {
	scanf("%s", S+1); N = (int)strlen(S+1);

	int m = 26;
	vector<int> cnt(max(m, N) + 1), x(N+1, 0), y(N+1, 0);
	for(int i=1; i<=m; i++) cnt[i] = 0;
	for(int i=1; i<=N; i++) cnt[x[i] = S[i]-'a'+1]++;
	for(int i=1; i<=m; i++) cnt[i] += cnt[i-1];
	for(int i=N; i>=1; i--) SA[cnt[x[i]]--] = i;
	for(int len = 1, p = 0; ; len<<=1, m = p, p = 0)
	{
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
			int al = SA[i]+len, bl = SA[i+1]+len;
			x[b] = (al<=N && bl<=N && y[a]==y[b] && y[al]==y[bl])?p:++p;
		}
		if(p == N) break;
	}

	vector<int> rank(N+1, 0);
	for(int i=1; i<=N; i++) rank[SA[i]] = i;
	for(int i=1, j, k=0; i<=N; LCP[rank[i++]] = k)
		for(k?k--:0, j=SA[rank[i]-1]; S[i+k] == S[j+k]; k++);
	int ans = 0;
	for(int i=1; i<=N; i++)
		ans = max(ans, LCP[i]);
	cout << ans;
	return 0;
}










