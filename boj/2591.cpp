// =====================================================================================
//
//       Filename:  2591.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 17:53:31
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

int Dy[44]; char A[44];
int main() {
	scanf("%s", A+1); int N = (int)strlen(A+1);
	Dy[0] = 1; if(A[1] != '0') Dy[1] = 1;
	for(int i=2; i<=N; i++)
	{
		int a = A[i-1] - '0', b = A[i] - '0';
		a = a*10 + b;
		if(a >= 10 && a <= 34) Dy[i] += Dy[i-2];
		if(b > 0) Dy[i] += Dy[i-1];
	}
	cout << Dy[N];
	return 0;
}










