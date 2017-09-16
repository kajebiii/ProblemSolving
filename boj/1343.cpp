// =====================================================================================
//
//       Filename:  1343.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 16:52:34
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
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int Cnt[555];
int main() {
	string S; cin >> S; int N = S.length();
	for(int i=N-1; i>=0; i--) 
		if(S[i] == 'X') Cnt[i] = Cnt[i+1] + 1;
	for(int i=0; i<N; i++)
	{
		if(S[i] == '.') continue;
		if(Cnt[i] % 2 == 1) {printf("-1"); return 0;}
		if(Cnt[i] > 2) {S[i]=S[i+1]=S[i+2]=S[i+3]='A'; i+=3;}
		else {S[i]=S[i+1]='B'; i+=1;}
	}
	cout << S;
	return 0;
}










