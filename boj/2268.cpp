// =====================================================================================
//
//       Filename:  2268.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/09/2016 12:51:53
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
const int MAX_N = 1e6 + 100;

int N, M, P;
ll T[MAX_N * 4];
void update(int v, int k) {T[v] = k; while(v/=2) {T[v] = T[v*2] + T[v*2+1];}}
ll get(int a, int b) {return a<=b?(get((a+1)/2, (b-1)/2) + (a%2==1?T[a]:0) + (b%2==0?T[b]:0)):0;}
int main() {
	cin >> N >> M;
	for(P=1; P<N; P<<=1);
	while(M--)
	{
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		if(t == 0 && x > y) swap(x, y);
		if(t == 0) printf("%lld\n", get(P+x-1, P+y-1));
		else update(P+x-1, y);
	}
	return 0;
}










