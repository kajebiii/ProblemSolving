// =====================================================================================
//
//       Filename:  1958.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 12:47:25
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

char A[111], B[111], C[111];
int AN, BN, CN;
int Dy[111][111][111];

int main() {
	scanf("%s%s%s", A+1, B+1, C+1);
	AN = (int)strlen(A+1);
	BN = (int)strlen(B+1);
	CN = (int)strlen(C+1);

	for(int i=1; i<=AN; i++) for(int j=1; j<=BN; j++) for(int k=1; k<=CN; k++)
	{
		Dy[i][j][k] = max(Dy[i-1][j][k], max(Dy[i][j-1][k], Dy[i][j][k-1]));
		if(A[i] == B[j] && B[j] == C[k])
			Dy[i][j][k] = max(Dy[i-1][j-1][k-1] + 1, Dy[i][j][k]);
	}
	cout << Dy[AN][BN][CN];
	return 0;
}










