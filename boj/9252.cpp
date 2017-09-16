// =====================================================================================
//
//       Filename:  9252.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 12:43:19
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

int Dy[1111][1111], P[1111][1111];
char A[1111], B[1111];
int AN, BN;

void printAns(int a, int b)
{
	if(a == 0 || b == 0) return;
	if(P[a][b] == 0) printAns(a-1, b);
	if(P[a][b] == 1) printAns(a, b-1);
	if(P[a][b] == 2) printAns(a-1, b-1);
	if(P[a][b] == 2) printf("%c", A[a]);
}

int main() {
	scanf("%s", A+1); scanf("%s", B+1);
	AN = (int)strlen(A+1), BN = (int)strlen(B+1);
	for(int i=1; i<=AN; i++) for(int j=1; j<=BN; j++)
	{
		Dy[i][j] = Dy[i-1][j]; P[i][j] = 0;
		if(Dy[i][j] < Dy[i][j-1])
			Dy[i][j] = Dy[i][j-1], P[i][j] = 1;
		if(A[i] == B[j] && Dy[i][j] < Dy[i-1][j-1] + 1)
			Dy[i][j] = Dy[i-1][j-1] + 1, P[i][j] = 2;
	}
	printf("%d\n", Dy[AN][BN]);
	printAns(AN, BN);
	return 0;
}










