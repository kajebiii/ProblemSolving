// =====================================================================================
//
//       Filename:  1895.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 17:54:48
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
const int MAX_N = 55;

int N, M, Nr[MAX_N][MAX_N], T;

int main() {
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &Nr[i][j]);
	scanf("%d", &T);

	int ans = 0;
	for(int i=1; i<N-1; i++) for(int j=1; j<M-1; j++)
	{
		int A[9], cnt = 0;
		for(int ki=-1; ki<=1; ki++) for(int kj=-1; kj<=1; kj++)
			A[cnt++] = Nr[i+ki][j+kj];
		sort(A, A+cnt);
		ans += (A[4] >= T);
	}
	cout << ans;
	return 0;
}










