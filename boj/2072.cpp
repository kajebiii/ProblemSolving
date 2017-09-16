// =====================================================================================
//
//       Filename:  2615.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 02:29:33
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
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(1, 0), mp(0, 1), mp(-1, 1), mp(1, 1)};

int Nr[44][44];
int get(int a, int b)
{
	if(a < 0 || b < 0) return 0;
	return Nr[a][b];
}
int main() {
	int N; cin >> N;
	for(int n=0; n<N; n++)
	{
		int x, y; scanf("%d%d", &x, &y);
		Nr[x-1][y-1] = 2 - n%2;
		for(int i=0; i<19; i++) for(int j=0; j<19; j++)
		{
			if(Nr[i][j] == 0) continue;
			for(int k=0; k<4; k++)
			{
				bool flag = true;
				for(int l=0; l<5; l++) if(get(i, j) != get(i+Ch[k].fi*l, j+Ch[k].se*l)) flag = false;
				for(int l=-1; l<=5; l+=6) if(get(i+Ch[k].fi*l, j+Ch[k].se*l) == get(i, j)) flag = false;
				if(flag) {printf("%d\n", n+1); return 0;}
			}
		}
	}
	puts("-1");
	return 0;
}










