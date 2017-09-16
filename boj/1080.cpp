// =====================================================================================
//
//       Filename:  1080.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  10/04/2016 15:35:59
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
#include <assert.h>

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
const pi Ch[9] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(-1, 1), mp(1, -1), mp(1, 1), mp(0, 0)};

int A[2][55][55], N, M;
int main() {
	cin >> N >> M;
	for(int k=0; k<2; k++) for(int i=0; i<N; i++) for(int j=0; j<M; j++)
		scanf("%1d", &A[k][i][j]);

	int ans = 0;
	for(int i=1; i<N-1; i++) for(int j=1; j<M-1; j++)
	{
		if(A[0][i-1][j-1] == A[1][i-1][j-1]) continue;
		ans++;
		for(int k=0; k<9; k++)
		{
			pi next = mp(i, j) + Ch[k];
			A[0][next.fi][next.se] ^= 1;
		}
	}
	bool isSame = true;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
		if(A[0][i][j] != A[1][i][j]) isSame = false;

	if(isSame) printf("%d\n", ans);
	else printf("-1");
	return 0;
}










