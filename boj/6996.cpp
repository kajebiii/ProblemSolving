// =====================================================================================
//
//       Filename:  6996.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 00:07:20
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

int Cnt[333];

int main() {
	int T; cin >> T;
	while(T--)
	{
		for(int i=0; i<333; i++) Cnt[i] = 0;
		string A, B; cin >> A >> B;
		for(char x : A) Cnt[x]++;
		for(char x : B) Cnt[x]--;
		bool isTrue = true;
		for(int i=0; i<333; i++) if(Cnt[i] != 0) isTrue = false;
		cout << A << " & " << B;
		if(isTrue) puts(" are anagrams.");
		else puts(" are NOT anagrams.");
	}
	return 0;
}










