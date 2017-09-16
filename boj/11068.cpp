// =====================================================================================
//
//       Filename:  11068.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 00:58:01
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

int main() {
	int T; cin >> T;
	while(T--)
	{
		int N; scanf("%d", &N);
		bool canMake = false;
		for(int b=2; b<=64; b++)
		{
			vector<int> V, RV;
			int n = N;
			while(n) {V.pb(n%b), n/=b;}
			RV = V; reverse(RV.begin(), RV.end());

			bool nowCan = true;
			for(int i=0; i<V.size(); i++)
				if(V[i] != RV[i]) nowCan = false;
			if(nowCan) canMake = true;
		}
		printf("%d\n", (int)canMake);
	}
	return 0;
}










