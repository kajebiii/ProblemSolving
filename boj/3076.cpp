// =====================================================================================
//
//       Filename:  3076.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/05/2016 15:04:20
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

char Map[111][111];
int R, C, A, B;

int main() {
	cin >> R >> C >> A >> B;
	for(int i=0; i<R; i++) for(int j=0; j<C; j++)
		for(int a=0; a<A; a++) for(int b=0; b<B; b++)
			Map[i*A+a][j*B+b] = ((i+j)%2)?'.':'X';
	for(int i=0; i<R*A; i++)
		puts(Map[i]);
	return 0;
}










