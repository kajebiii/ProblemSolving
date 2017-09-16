// =====================================================================================
//
//       Filename:  2841.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 16:06:24
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

int N, P;
stack<int> S[9];

int main() {
	cin >> N >> P;
	int Ans = 0;
	for(int i=0; i<N; i++)
	{
		int t, p; scanf("%d%d", &t, &p);
		while(!S[t].empty() && S[t].top() > p) {S[t].pop(); Ans++;}
		if(!S[t].empty() && S[t].top() == p) continue;
		S[t].push(p); Ans++;
	}
	cout << Ans;
	return 0;
}










