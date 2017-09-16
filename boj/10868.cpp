// =====================================================================================
//
//       Filename:  10868.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/07/2016 09:45:40
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
const int MAX_N = 1e5 + 100;

int N, M, T[MAX_N*4], P;

void update(int v, int k) {T[v] = k; while(v/=2) T[v] = min(T[v*2], T[v*2+1]);}
int get(int a, int b) {return a<=b?min(get((a+1)/2, (b-1)/2), min(T[a], T[b])):INF;}
int main() {
	cin >> N >> M; for(P=1; P<N; P<<=1);
	for(int i=0; i<N; i++) scanf("%d", &T[P+i]);
	for(int i=N; i<P; i++) T[P+i] = INF;
	for(int i=P-1; i>=1; i--) T[i] = min(T[i*2], T[i*2+1]);
	while(M--)
	{
		int x, y; scanf("%d%d", &x, &y);
		printf("%d\n", get(P+x-1, P+y-1));
	}
	return 0;
}










