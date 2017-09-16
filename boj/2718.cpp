// =====================================================================================
//
//       Filename:  2718.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 00:56:34
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
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int Dy[99][16];
int main() {
	int T; cin >> T;
	Dy[0][15] = 1; 
	for(int n=1; n<=50; n++)
		for(int s=0; s<16; s++)
			for(int k=0; k<8; k++)
			{
				int now = s; bool isCan = true;
				for(int i=0; i<3; i++)
					if((k>>i) % 2)
					{
						if(now & 1<<i || now & 1<<i+1) isCan = false;
						else now |= 1<<i, now |= 1<<i+1;
					}
				if(isCan == false) continue;
				Dy[n][now] += Dy[n-1][15 - s];
			}
	while(T--)
	{
		int x; scanf("%d", &x);
		printf("%d\n", Dy[x][15]);
	}
	return 0;
}










