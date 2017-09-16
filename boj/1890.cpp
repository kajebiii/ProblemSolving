// =====================================================================================
//
//       Filename:  1890.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 18:47:29
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

int N;
long long Dy[111][111];
int main() {
	cin >> N;
	Dy[0][0] = 1;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++)
	{
		int x; scanf("%d", &x);
		if(x == 0) continue;
		Dy[i+x][j] += Dy[i][j];
		Dy[i][j+x] += Dy[i][j];
	}
	cout << Dy[N-1][N-1];
	return 0;
}










