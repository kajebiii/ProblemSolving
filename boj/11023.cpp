// =====================================================================================
//
//       Filename:  11024.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 18:21:24
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
	int T = 1;
	char data[999];
	while(T--)
	{
		fgets(data, 999, stdin);
		int sum = 0, now = 0;
		for(int i=0; data[i]; i++)
		{
			if(data[i] >= '0') now *= 10, now += data[i] - '0';
			else sum += now, now = 0;
		}
		printf("%d\n", sum);
	}
	return 0;
}










