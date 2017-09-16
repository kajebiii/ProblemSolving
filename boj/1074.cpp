// =====================================================================================
//
//       Filename:  1074.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/04/2016 16:18:09
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

int getAns(int x, int y, int k, int r, int c)
{
	if(k == 1) return 0;
	int base = 0;
	for(int i=0; i<2; i++) for(int j=0; j<2; j++)
	{
		if(x+i*k/2 <= r && r < x+(i+1)*k/2)
			if(y+j*k/2 <= c && c < y+(j+1)*k/2)
				return base + getAns(x+i*k/2, y+j*k/2, k/2, r, c);
		base += k/2 * k/2;
	}
	return -1;
}
int main() {
	int N, R, C;
	while(scanf("%d%d%d", &N, &R, &C) != EOF)
		printf("%d\n", getAns(0, 0, 1<<N, R, C));
	return 0;
}










