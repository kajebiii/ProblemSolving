// =====================================================================================
//
//       Filename:  1821.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/09/2016 13:15:12
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

int N, F;
int C[11][11], A[11], Ans[11];
int main() {
	cin >> N >> F;
	for(int i=0; i<=N; C[i][0] = 1, i++) 
		for(int j=1; j<=i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
	for(int i=0; i<N; i++) A[i] = i+1;
	do
	{
		int now = 0;
		for(int i=0; i<N; i++)
			now += A[i] * C[N-1][i];
		if(now == F)
		{
			for(int i=0; i<N; i++) Ans[i] = A[i];
			break;
		}
	}while(next_permutation(A, A+N));
	for(int i=0; i<N; i++) printf("%d ", Ans[i]);
	return 0;
}










