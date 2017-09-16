// =====================================================================================
//
//       Filename:  2458.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 14:05:47
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

int N, M, Cnt[555];
bool V[555][555];

int main() {
	cin >> N >> M;
	while(M--)
	{
		int x, y; scanf("%d%d", &x, &y);
		V[x][y] = true;
	}
	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(V[i][k] && V[k][j]) V[i][j] = true;
	int ans = 0;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(V[i][j]) Cnt[i]++, Cnt[j]++;
	for(int i=1; i<=N; i++) if(Cnt[i] == N-1) ans++;
	cout << ans;
	return 0;
}










