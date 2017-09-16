// =====================================================================================
//
//       Filename:  2851.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 15:08:32
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

int S[22];
bool cmp(int a, int b)
{
	return abs(100-a)==abs(100-b)?a>b:abs(100-a)<abs(100-b);
}
int main() {
	for(int x, i=1; i<=10; i++) cin >> x, S[i] = S[i-1] + x;
	sort(S+1, S+10+1, cmp);
	printf("%d\n", S[1]);
	return 0;
}










