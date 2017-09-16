// =====================================================================================
//
//       Filename:  9248.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/30/2016 10:51:13
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
const int MAX_N = 5e5 + 500;

int N, SA[MAX_N];
char S[MAX_N];

void getSA()
{
	int i, j, k;
	int m = 26;
	vector<int> cnt(max(N,m)+1, 0), x(N+1, 0), y(N+1, 0);
	for(i=1; i<=N; i++) cnt[x[i] = S[i] - 'a' + 1]++;
	for(i=1; i<=m; i++) cnt[i] += cnt[i-1];
	for(i=N; i>=1; i--) SA[cnt[x[i]]--] = i;
	for(int len=1, p=0; p<N; len<<=1, m = p)
	{
		for(p=0, i=N-len+1; i<=N; i++) y[++p] = i;
		for(i=1; i<=N; i++) if(SA[i] > len) y[++p] = SA[i] - len;
		for(i=0; i<=m; i++) cnt[i] = 0;
		for(i=1; i<=N; i++) cnt[x[y[i]]]++;
		for(i=1; i<=m; i++) cnt[i] += cnt[i-1];
		for(i=N; i>=1; i--) SA[cnt[x[y[i]]]--] = y[i];
		swap(x, y);
		p = 1; x[SA[1]] = 1;
		for(i=1; i<N; i++)
		{
			int a = SA[i], b = SA[i+1], al = SA[i]+len, bl = SA[i+1]+len;
			x[SA[i+1]] = (al <= N && bl <= N && y[a] == y[b] && y[al] == y[bl]) ? p : ++p;
		}
	}
}
int LCP[MAX_N];
void getLCP()
{
	int i, j, k=0;
	vector<int> rank(N+1, 0);
	for(i=1; i<=N; i++) rank[SA[i]] = i;
	for(i=1; i<=N; LCP[rank[i++]] = k)
		for(k ? k--:0, j = SA[rank[i]-1]; S[i+k] == S[j+k]; k++);
}

int main() {
	scanf("%s", S+1);
	N = (int)strlen(S+1);
	getSA();
	getLCP();

	for(int i=1; i<=N; i++) printf("%d ", SA[i]); printf("\n");
	printf("x");
	for(int i=2; i<=N; i++) printf(" %d", LCP[i]);
	return 0;
}










