// =====================================================================================
//
//       Filename:  10837.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/09/2016 10:41:42
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

int K, C;
bool Dy[1111][1111];
int main() {
	cin >> K >> C;
	Dy[0][0] = true;
	for(int p=1; p<=2*K; p++)
	{
		for(int i=0; i<=K; i++)
		{
			int j = p - i; if(j > K || j < 0) continue;
			if(i == j) {Dy[i][j] = true; continue;}
			if(i > j)
				Dy[i][j] = Dy[i-1][j] && (K - i + 1 >= i - j - 1);
			else 
				Dy[i][j] = Dy[i][j-1] && (K - j>= j - i - 1);
		}
	}
	while(C--)
	{
		int x, y; scanf("%d%d", &x, &y);
		printf("%d\n", Dy[x][y]);
	}
	return 0;
}










