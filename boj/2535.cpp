// =====================================================================================
//
//       Filename:  2535.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 14:51:02
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

struct DATA
{
	int a, b, s;
	const bool operator<(const DATA &o) const{return s > o.s;}
}D[111];

int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++) scanf("%d%d%d", &D[i].a, &D[i].b, &D[i].s);
	sort(D, D+N);
	for(int i=0; i<2; i++) printf("%d %d\n", D[i].a, D[i].b);
	if(D[0].a == D[1].a)
	{
		for(int i=2; i<N; i++) if(D[i].a != D[0].a)
			{printf("%d %d\n", D[i].a, D[i].b); break;}
	}
	else
		printf("%d %d\n", D[2].a, D[2].b);
	return 0;
}










