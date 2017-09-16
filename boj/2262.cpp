// =====================================================================================
//
//       Filename:  2262.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 18:14:43
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

int N, Dy[333][333], minV[333][333], Nr[333];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	for(int i=0; i<N; i++) for(int j=i; j<N; j++) 
		minV[i][j] = Nr[min_element(Nr+i, Nr+j+1) - Nr];
	for(int i=0; i<N; i++) for(int j=i+1; j<N; j++)
		Dy[i][j] = INF;
	for(int p=1; p<N; p++) for(int i=0; i<N-p; i++)
	{
		int j = i + p;
		for(int k=i; k<j; k++) 
			Dy[i][j] = min(Dy[i][j], Dy[i][k] + Dy[k+1][j] + abs(minV[i][k] - minV[k+1][j]));
	}
	cout << Dy[0][N-1];
	return 0;
}










