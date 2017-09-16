// =====================================================================================
//
//       Filename:  4597.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 17:13:30
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
	while(1)
	{
		string S; cin >> S;
		if(S[0] == '#') break;
		int N = S.length();
		int cnt = 0;
		for(int i=0; i<N; i++) if(S[i] == '1') cnt++;
		if(S[N-1] == 'e') S[N-1] = cnt%2 + '0';
		else S[N-1] = 1-cnt%2 + '0';
		cout << S << endl;
	}
	return 0;
}










