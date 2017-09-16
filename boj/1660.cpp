// =====================================================================================
//
//       Filename:  1660.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 20:24:59
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

int Sum[999], Dy[333333];
int main() {
	int N; cin >> N;
	for(int i=1; i<=200; i++) Sum[i] = Sum[i-1] + i*(i+1)/2;
	for(int i=1; i<=N; i++) Dy[i] = INF;
	for(int k=1; k<=200; k++)
		for(int i=0; i<=N-Sum[k]; i++)
			Dy[i+Sum[k]] = min(Dy[i+Sum[k]], Dy[i] + 1);
	cout << Dy[N];
	return 0;
}










