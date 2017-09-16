// =====================================================================================
//
//       Filename:  5557.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 17:30:29
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

int N, Nr[111];
ll Dy[111][21];
int main() {
	scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	Dy[1][Nr[1]] = 1;
	for(int i=2; i<N; i++)
	{
		for(int j=0; j<=20-Nr[i]; j++)
			Dy[i][j] += Dy[i-1][j+Nr[i]];
		for(int j=20; j>=Nr[i]; j--)
			Dy[i][j] += Dy[i-1][j-Nr[i]];
	}
	cout << Dy[N-1][Nr[N]];
	return 0;
}










