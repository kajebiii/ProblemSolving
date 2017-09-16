// =====================================================================================
//
//       Filename:  11444.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/27/2016 14:19:01
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
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>
#include <assert.h>
#include <memory.h>

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
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MOD = 1e9 + 7;

struct MAT
{
	int A[2][2];
	MAT operator *(MAT o)
	{
		int B[2][2];
		memcpy(B, A, sizeof(B));
		memset(A, 0, sizeof(A));
		for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++)
			A[i][j] = (A[i][j] + 1ll*B[i][k] * o.A[k][j]%MOD) % MOD;
		return *this;
	}
};
ll N;
int main() {
	cin >> N;
	if(N % 2 == 0) N++;
	MAT result, power;
	result.A[0][0] = result.A[1][1] = 1; result.A[1][0] = result.A[0][1] = 0;
	power.A[0][0] = power.A[0][1] = power.A[1][0] = 1; power.A[1][1] = 0;
	while(N)
	{
		if(N % 2) result = result * power;
		power = power * power;
		N /= 2;
	}
	printf("%d\n", (result.A[0][1] + MOD - 1) % MOD);
	return 0;
}










