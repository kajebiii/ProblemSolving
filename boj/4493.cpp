// =====================================================================================
//
//       Filename:  4493.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/04/2016 16:24:33
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
		int N; scanf("%d", &N);
		int cnt[2] = {0, 0};
		for(int i=0; i<N; i++)
		{
			char x, y; scanf("\n%c %c", &x, &y);
			if(x == y) continue;
			if(x == 'R')
				if(y == 'S') cnt[0]++;
				else cnt[1]++;
			else if(x == 'S')
				if(y == 'P') cnt[0]++;
				else cnt[1]++;
			else
				if(y == 'R') cnt[0]++;
				else cnt[1]++;
		}
		if(cnt[0] > cnt[1]) puts("Player 1");
		else if(cnt[0] < cnt[1]) puts("Player 2");
		else puts("TIE");
	}
	return 0;
}










