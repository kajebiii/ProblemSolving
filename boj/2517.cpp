// =====================================================================================
//
//       Filename:  2517.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 03:51:52
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
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 5e5 + 100;

int sNr[MAX_N];
int N, Nr[MAX_N], T[MAX_N*4], P;
void U(int v, int k) {T[v] = k; while(v/=2) T[v] = T[v*2] + T[v*2+1];}
int G(int a, int b) {return a<=b?G((a+1)/2, (b-1)/2)+(a%2?T[a]:0)+(b%2==0?T[b]:0):0;}
int main() {
	scanf("%d", &N); for(int i=0; i<N; i++) scanf("%d", &Nr[i]), sNr[i] = Nr[i];
	sort(sNr, sNr + N);
	for(int i=0; i<N; i++) Nr[i] = (int)(lower_bound(sNr, sNr+N, Nr[i]) - sNr);
	for(P=1; P<N; P<<=1);
	for(int i=0; i<N; i++)
	{
		int ans = G(P+Nr[i], P+N-1);
		U(P+Nr[i], 1);
		printf("%d\n", ans+1);
	}
	return 0;
}










