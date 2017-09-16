// =====================================================================================
//
//       Filename:  9226.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 23:21:00
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

char Data[99];
int Chk[999];

int main() {
	Chk['a'] = Chk['e'] = Chk['i'] = Chk['o'] = Chk['u'] = 1;
	while(1)
	{
		scanf("%s", Data);
		if(Data[0] == '#') break;
		int i; for(i=0; Data[i]; i++) if(Chk[Data[i]] == 1) break;
		printf("%s", Data+i);
		Data[i] = 0;
		printf("%say\n", Data);
	}
	return 0;
}










