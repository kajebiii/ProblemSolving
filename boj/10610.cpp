// =====================================================================================
//
//       Filename:  10610.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 23:36:46
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

string S;
int Cnt[10], Sum, N;
int main() {
	cin >> S;
	for(char x : S)
	{
		int now = x - '0';
		Cnt[now]++;
		Sum += now;
	}
	if(Cnt[0] == 0 || Sum % 3 != 0)
		printf("-1");
	else
	{
		for(int i=9; i>=0; i--)
			for(int j=Cnt[i]; j>=1; j--)
				printf("%d", i);
	}
	return 0;
}










