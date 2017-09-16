// =====================================================================================
//
//       Filename:  4883.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 02:09:14
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

int Dy[111111][3];
int main() {
	for(int t=1; ; t++)
	{
		int N; scanf("%d", &N);
		if(N == 0) break;
		int A, B;
		for(int j=0; j<3; j++) scanf("%d", &Dy[1][j]);
		Dy[1][0] = INF / 2; Dy[1][2] += Dy[1][1];
		for(int i=2; i<=N; i++)
		{
			int Nr[3]; for(int j=0; j<3; j++) scanf("%d", &Nr[j]);
			for(int j=0; j<3; j++) Dy[i][j] = INF;
			for(int j=0; j<3; j++) for(int k=-1; k<=1; k++)
			{
				int l = j+k; if(l < 0 || l >= 3) continue;
				Dy[i][j] = min(Dy[i][j], Dy[i-1][l] + Nr[j]);
			}
			for(int j=1; j<3; j++) Dy[i][j] = min(Dy[i][j], Dy[i][j-1] + Nr[j]);
		}
		printf("%d. %d\n", t, Dy[N][1]);
	}
	return 0;
}










