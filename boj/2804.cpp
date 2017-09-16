// =====================================================================================
//
//       Filename:  2804.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 22:46:00
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int main() {
	string A, B; cin >> A >> B;
	for(int i=0; i<A.length(); i++) for(int j=0; j<B.length(); j++)
		if(A[i] == B[j])
		{
			for(int x=0; x<B.length(); x++, puts("")) for(int y=0; y<A.length(); y++)
			{
				if(x == j) printf("%c", A[y]);
				else if(y == i) printf("%c", B[x]);
				else printf(".");
			}
			return 0;
		}
	return 0;
}










