// =====================================================================================
//
//       Filename:  2607.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 00:49:22
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
	int N; cin >> N;
	string A; cin >> A;
	int ans = 0;
	for(int i=1; i<N; i++)
	{
		string K; cin >> K;
		for(int i=0; i<333; i++) Cnt[i] = 0;
		for(char x : A) Cnt[x]++;
		for(char x : K) Cnt[x]--;
		int other, cntm1, cntp1;
		other= cntm1 = cntp1 = 0;
		for(int i=0; i<333; i++)
		{
			if(Cnt[i] == 0) continue;
			if(Cnt[i] == 1) cntp1++;
			else if(Cnt[i] == -1) cntm1++;
			else other++;
		}
		if(other >= 1) continue;
		if(cntm1 + cntp1 <= 2 && max(cntm1, cntp1) <= 1) ans++;
	}
	cout << ans;
	return 0;
}










