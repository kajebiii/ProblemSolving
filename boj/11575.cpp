// =====================================================================================
//
//       Filename:  11575.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 19:50:15
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

char C[1111111];
int main() {
	int T; cin >> T;
	while(T--)
	{
		int a, b; scanf("%d%d\n", &a, &b);
		scanf("%s", C);
		for(int i=0; C[i]; i++)
			printf("%c", (a*(C[i]-'A')+b) % 26 + 'A');
		printf("\n");
	}
	return 0;
}










