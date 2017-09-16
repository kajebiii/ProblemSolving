// =====================================================================================
//
//       Filename:  7517.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 00:21:44
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

int A[2][101101];
int main() {
	int N, M; cin >> N >> M;
	for(int i=0; i<M; i++) scanf("%d%d", &A[0][i], &A[1][i]);
	for(int i=0; i<2; i++) sort(A[i], A[i]+M);
	int Ans = 0;
	for(int k=0; k<2; k++) for(int i=0; i<M/2; i++)
		Ans += A[k][M-1-i] - A[k][i];
	cout << Ans;
	return 0;
}










