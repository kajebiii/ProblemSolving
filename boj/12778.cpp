// =====================================================================================
//
//       Filename:  12778.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 16:01:46
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

int main() {
	int T; cin >> T;
	while(T--)
	{
		int N; char t; scanf("%d %c\n", &N, &t);
		if(t == 'C')
		{
			for(int i=0; i<N; i++)
			{
				char x; scanf("%c ", &x);
				printf("%d ", x - 'A' + 1);
			}
		}
		else
		{
			for(int x, i=0; i<N; i++) scanf("%d", &x), printf("%c ", x + 'A' - 1);
		}
		puts("");
	}
	return 0;
}










