// =====================================================================================
//
//       Filename:  1356.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/05/2016 10:33:21
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

int getMulti(int v)
{
	int r = v % 10;
	while(v/=10) r *= v%10;
	return r;
}
int main() {	
	int N; cin >> N;
	int A = N, B = N % 10;
	while(A /= 10)
	{
		if(getMulti(A) == B) {puts("YES"); return 0;}
		B *= A % 10;
	}
	puts("NO");
	return 0;
}










