// =====================================================================================
//
//       Filename:  2407.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 12:52:15
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

struct BIGINT
{
	int A[111];
	BIGINT()
	{
		for(int i=0; i<111; i++) A[i] = 0;
	}
	BIGINT(int v)
	{
		for(int i=0; i<111; i++) A[i] = 0;
		A[0] = v;
	}
	const BIGINT operator+(const BIGINT &X) const
	{
		BIGINT R;
		for(int i=0; i<110; i++) R.A[i] = 0;
		for(int i=0; i<110; i++)
		{
			R.A[i] += A[i] + X.A[i];
			R.A[i+1] += R.A[i] / 10;
			R.A[i] %= 10;
		}
		return R;
	}
}C[111][111];
int N, M;

int main() {
	cin >> N >> M;
	int i, j;
	for(i=1, C[0][0] = BIGINT(1); i<=N; i++) for(j=1, C[i][0] = BIGINT(1); j<=M; j++)
		C[i][j] = C[i-1][j-1] + C[i-1][j];
	bool print = false;
	for(int i=110; i>=0; i--)
	{
		if(C[N][M].A[i] != 0) print = true;
		if(print) printf("%d", C[N][M].A[i]);
	}
	return 0;
}










