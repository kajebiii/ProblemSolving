// =====================================================================================
//
//       Filename:  11586.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 18:43:21
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

int N, K;
char A[111][111];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%s", A[i]); cin >> K;
	for(int i=0; i<N; i++, puts("")) for(int j=0; j<N; j++)
	{
		if(K == 1) printf("%c", A[i][j]);
		else if(K == 2) printf("%c", A[i][N-1-j]);
		else printf("%c", A[N-1-i][j]);
	}
	return 0;
}










