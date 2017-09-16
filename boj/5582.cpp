// =====================================================================================
//
//       Filename:  5582.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 19:50:01
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int N, M;
char S[8888];

int SA[8888], LCP[8888];
void getSALCP()
{
	int i, j, m = 200;
	vector<int> cnt(max(N, m)+1, 0), x(N+1, 0), y(N+1, 0);
	for(i=1; i<=N; i++) cnt[x[i] = S[i]]++;
	for(i=1; i<=m; i++) cnt[i] += cnt[i-1];
	for(i=N; i>=1; i--) SA[cnt[x[i]]--] = i;
	for(int len=1, p=1; p<N; len<<=1 , m=p)
	{
		for(p=0, i=N-len+1; i<=N; i++) y[++p] = i;
		for(i=1; i<=N; i++) if(SA[i] > len) y[++p] = SA[i] - len;
		for(i=1; i<=m; i++) cnt[i] = 0;
		for(i=1; i<=N; i++) cnt[x[y[i]]]++;
		for(i=1; i<=m; i++) cnt[i] += cnt[i-1];
		for(i=N; i>=1; i--) SA[cnt[x[y[i]]]--] = y[i];
		swap(x, y); p = 1; x[SA[1]] = 1;
		for(i=1; i<N; i++)
		{
			int a = SA[i], b = SA[i+1];
			int al = SA[i]+len, bl = SA[i+1]+len;
			x[b] = (al<=N&&bl<=N&&y[a]==y[b]&&y[al]==y[bl])?p:++p;
		}
	}
	int k=0;
	vector<int> rank(N+1, 0);
	for(i=1; i<=N; i++) rank[SA[i]] = i;
	for(i=1; i<=N; LCP[rank[i++]]=k)
		for(k?k--:0, j=SA[rank[i]-1]; S[i+k]==S[j+k]; k++);
}

int main() {
	scanf("%s", S+1); N = (int)strlen(S+1); S[N+1] = '#';
	scanf("%s", S+N+2); M = (int)strlen(S+N+2); N += M + 1;
	getSALCP();
	
	int ans = 0;
	int now = -1;
	for(int i=1; i<=N; i++)
		if(SA[i] < N-M) now = INF;
		else if( (now = min(now, LCP[i  ])) != -1) ans = max(ans, now);
	now = -1;
	for(int i=N; i>=1; i--)
		if(SA[i] < N-M) now = INF;
		else if( (now = min(now, LCP[i+1])) != -1) ans = max(ans, now);

	cout << ans;
	return 0;
}










