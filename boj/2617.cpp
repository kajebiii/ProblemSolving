// =====================================================================================
//
//       Filename:  2617.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 18:09:15
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

int N, M, V[111][111];
int Cnt[111][2];

int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) V[i][j] = INF;
	for(int k=0; k<M; k++)
	{
		int x, y; scanf("%d%d", &x, &y);
		V[x][y] = 1;
	}
	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(V[i][k] != INF && V[k][j] != INF)
			V[i][j] = min(V[i][j], V[i][k] + V[k][j]);

	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(V[i][j] != INF) Cnt[i][0]++, Cnt[j][1]++;
	int ans = 0;
	for(int i=1; i<=N; i++)
		if(Cnt[i][0] >= (N+1)/2 || Cnt[i][1] >= (N+1)/2) ans++;
	cout << ans;
	return 0;
}










