// =====================================================================================
//
//       Filename:  11944.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 00:56:27
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
	string N; int M; cin >> N >> M;
	int RN = 0;
	for(char x : N)
		RN *= 10, RN += x - '0';
	int cnt = 0, i = 0, num = 0;
	while(cnt < M)
	{
		printf("%c", N[i]);
		i += 1;
		num += (i / N.length());
		if(num == RN) break;
		i %= (int)N.length();
		cnt++;
	}
	return 0;
}










