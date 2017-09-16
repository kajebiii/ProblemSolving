// =====================================================================================
//
//       Filename:  2467.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 01:49:40
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

int Nr[111111];
int main() {
	int N; cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	int l = 0, r = N-1, ansl = -1, ansr = -1, ansv = INF;
	while(l < r)
	{
		int now = Nr[r] + Nr[l];
		if(abs(now) < ansv) {ansv = abs(now), ansl = Nr[l], ansr = Nr[r];}
		if(now >= 0) r--;
		else l++;
	}
	cout << ansl << " " << ansr;
	return 0;
}









