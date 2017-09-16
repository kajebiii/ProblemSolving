// =====================================================================================
//
//       Filename:  2629.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 00:29:15
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

bool Dy[33][33333];

int main() {
	int N; cin >> N;
	Dy[0][16000] = true;
	for(int i=1, x; i<=N; i++)
	{
		scanf("%d", &x);
		for(int j=0; j<32000; j++)
			if(Dy[i-1][j])
				Dy[i][j-x] = Dy[i][j] = Dy[i][j+x] = true;
	}
	int M; cin >> M;
	for(int i=0, x; i<M; i++)
	{
		scanf("%d", &x);
		printf("%c ", Dy[N][x+16000]?'Y':'N');
	}
	return 0;
}










