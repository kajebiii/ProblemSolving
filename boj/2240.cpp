// =====================================================================================
//
//       Filename:  2240.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 20:41:00
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

int Dy[33];

int main() {
	int T, W; cin >> T >> W;
	Dy[0] = 1;
	for(int t=1; t<=T; t++)
	{
		int x; scanf("%d", &x); x--;
		for(int i=x; i<=W; i+=2) 
			if(Dy[i]) Dy[i]++;
		for(int i=1-x; i<=W; i+=2)
			if(Dy[i]) Dy[i+1] = max(Dy[i]+1, Dy[i+1]);
	}
	cout << Dy[max_element(Dy+0, Dy+W+1)-Dy]-1;
	return 0;
}










