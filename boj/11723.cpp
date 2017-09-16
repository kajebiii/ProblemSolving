// =====================================================================================
//
//       Filename:  11723.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 02:09:19
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

char A[9];
int main() {
	int M; cin >> M; scanf("\n");
	int now = 0;
	while(M--)
	{
		scanf("%s", A);
		int x;
		if(A[1] != 'l' && A[1] != 'm') scanf("%d", &x);
		if(A[1] == 'l') now = (1<<21)-1;
		if(A[1] == 'd') now |= (1<<x);
		if(A[1] == 'e') now &= (~(1<<x));
		if(A[1] == 'h') printf("%d\n", now&(1<<x)?1:0);
		if(A[1] == 'o') now ^= (1<<x);
		if(A[1] == 'm') now = 0;
	}
	return 0;
}










