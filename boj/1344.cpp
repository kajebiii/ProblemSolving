// =====================================================================================
//
//       Filename:  1344.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 22:38:26
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
#include <assert.h>

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

bool notP[20];
long double Dy[20][20];
int main() {
	notP[1] = notP[0] = true; for(int i=2; i<=18; i++) if(notP[i] == false) for(int j=i*2; j<=18; j+=i) notP[j] = true;
	Dy[0][0] = 1;
	long double A, B; scanf("%Lf%Lf", &A, &B); A/=100; B/=100;
	for(int l=0; l<18; l++)
	{
		for(int i=18; i>=0; i--) for(int j=18; j>=0; j--)
		{
			Dy[i][j] = (Dy[i][j] * (1-A) * (1-B));
			if(i>0 && j>0) Dy[i][j] += Dy[i-1][j-1] * A * B;
			if(i>0) Dy[i][j] += Dy[i-1][j] * A * (1-B);
			if(j>0) Dy[i][j] += Dy[i][j-1] * B * (1-A);
		}
	}
	long double ans = 0;
	for(int i=0; i<=18; i++) for(int j=0; j<=18; j++)
		if(!notP[i] || !notP[j]) ans += Dy[i][j];
	printf("%.15Lf", ans);
	return 0;
}










