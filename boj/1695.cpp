// =====================================================================================
//
//       Filename:  1695.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 21:27:09
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
const int MAX_N = 5005;

int N, Nr[MAX_N], Dy[MAX_N][MAX_N];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]), Dy[i][i] = 0;
	for(int k=1; k<N; k++)
		for(int i=0; i<N-k; i++)
		{
			Dy[i][i+k] = min(Dy[i+1][i+k], Dy[i][i+k-1]) + 1;
			if(Nr[i] == Nr[i+k])
				Dy[i][i+k] = min(Dy[i][i+k], Dy[i+1][i+k-1]);
		}
	cout << Dy[0][N-1];
	return 0;
}










