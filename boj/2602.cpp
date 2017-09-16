// =====================================================================================
//
//       Filename:  2602.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/04/2016 16:57:37
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
char C[22], A[2][111];
int Dy[22][2][111];
int main() {
	scanf("%s", C); M = (int)strlen(C);
	for(int i=0; i<2; i++) scanf("%s", A[i]); N = (int)strlen(A[0]);
	for(int i=0; i<2; i++) for(int j=0; j<N; j++) 
		if(A[i][j] == C[0]) Dy[0][i][j] = 1;
	for(int i=1; i<M; i++) for(int k=0; k<2; k++) for(int j=0; j<N; j++)
	{
		if(A[k][j] != C[i]) continue;
		for(int l=0; l<j; l++)
			if(A[1-k][l] == C[i-1])
				Dy[i][k][j] += Dy[i-1][1-k][l];
	}
	int ans = 0;
	for(int i=0; i<2; i++) for(int j=0; j<N; j++) ans += Dy[M-1][i][j];
	cout << ans;
	return 0;
}










