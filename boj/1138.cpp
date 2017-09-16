// =====================================================================================
//
//       Filename:  1138.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/04/2016 17:03:11
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

int Ans[99];
int main() {
	int N; cin >> N;
	for(int i=1; i<=N; i++)
	{
		int cnt = 0, x, j; cin >> x;
		for(j=1; j<=N; j++)
			if(Ans[j] == 0) if(++cnt == x+1) break;
		Ans[j] = i;
	}
	for(int i=1; i<=N; i++) printf("%d ", Ans[i]);
	return 0;
}










