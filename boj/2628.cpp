// =====================================================================================
//
//       Filename:  2628.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 23:16:46
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

vector<int> A[2];
int main() {
	int N, M; cin >> M >> N;
	A[0].pb(0); A[1].pb(0);
	int T; cin >> T;
	for(int i=0; i<T; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		A[x].pb(y);
	}
	A[0].pb(N); A[1].pb(M);
	for(int i=0; i<2; i++) sort(A[i].begin(), A[i].end());
	int mx[2] = {-1, -1};
	for(int i=0; i<2; i++) for(int j=1; j<A[i].size(); j++)
		mx[i] = max(mx[i], A[i][j] - A[i][j-1]);
	printf("%d", mx[0]*mx[1]);
	return 0;
}










