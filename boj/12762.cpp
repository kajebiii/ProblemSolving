// =====================================================================================
//
//       Filename:  12762.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 16:44:33
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

int A[1111], AN, N, Nr[1111];
int Val[1111];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]), Nr[i] *= -1;
	for(int i=0; i<N; i++)
	{
		int ix = (int)(lower_bound(A, A+AN, Nr[i]) - A);
		if(ix == AN) AN++;
		A[ix] = Nr[i];
		Val[i] += AN;
		if(debug) printf("[%d %d]\n", i, AN);
	}
	AN = 0;
	for(int i=N-1; i>=0; i--)
	{
		int ix = (int)(lower_bound(A, A+AN, Nr[i]) - A);
		if(ix == AN) AN++;
		A[ix] = Nr[i];
		Val[i] += AN;
		if(debug) printf("[%d %d]\n", i, AN);
	}
	int maxV = 0;
	for(int i=0; i<N; i++) maxV = max(maxV, Val[i] - 1);
	cout << maxV;
	return 0;
}









