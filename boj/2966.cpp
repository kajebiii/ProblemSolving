// =====================================================================================
//
//       Filename:  2966.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 23:37:57
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
#ifndef ONLINE_JUDGE
const bool debug = true;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int myMax(int a, int b) {return a>b?a:b;}
int main() {
	int N; cin >> N; string S; cin >> S;
	string Who[3] = {"Adrian", "Bruno", "Goran"};
	int Cnt[3] = {0, 0, 0};
	char Rep[3][6] = {{'A', 'B', 'C'}, {'B', 'A', 'B', 'C'}, {'C', 'C', 'A', 'A', 'B', 'B'}};
	int RepN[3] = {3, 4, 6};
	for(int i=0; i<S.length(); i++)
		for(int k=0; k<3; k++)
			if(S[i] == Rep[k][i%RepN[k]])
				Cnt[k]++;
	int maxV = accumulate(Cnt, Cnt+3, 0, myMax);
	printf("%d\n", maxV);
	for(int i=0; i<3; i++) if(maxV == Cnt[i]) cout << Who[i] << " ";
	return 0;
}










