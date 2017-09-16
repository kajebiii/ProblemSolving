// =====================================================================================
//
//       Filename:  11383.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/09/2016 10:06:54
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
char A[11][11], B[11][21];

int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++) scanf("%s", A[i]);
	for(int i=0; i<N; i++) scanf("%s", B[i]);
	bool isTrue = true;
	for(int i=0; i<N; i++)
		for(int j=0; j<2*M; j++)
			if(A[i][j/2] != B[i][j])
				isTrue = false;
	if(isTrue)
		puts("Eyfa");
	else
		puts("Not Eyfa");
	return 0;
}










