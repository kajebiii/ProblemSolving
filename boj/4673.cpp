// =====================================================================================
//
//       Filename:  4673.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 15:02:44
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

bool Chk[11111];
int main() {
	for(int i=1; i<=10000; i++)
	{
		int cnt = 0;
		int n = i; while(n) {cnt += n%10; n/=10;}
		Chk[i+cnt] = true;
	}
	for(int i=1; i<=10000; i++)
		if(!Chk[i]) printf("%d\n", i);
	return 0;
}










