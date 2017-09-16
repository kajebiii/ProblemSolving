// =====================================================================================
//
//       Filename:  1990.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 15:38:54
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

vector<int> Prime;
bool notP[10000002];
int main() {
	int A, B; cin >> A >> B;
	notP[1] = true; for(int i=2; i<10000000; i++) if(notP[i] == false) for(int j=i*2; j<10000000; j+=i) notP[j] = true;
	if(11 >= A && 11 <= B) Prime.pb(11);
	for(int m=0; m<10; m++)
	{
		if(!notP[m] && m >= A && m <= B) Prime.pb(m);
		for(int i=1; i<1000; i++)
		{
			vector<int> V;
			int n = i;
			do{V.pb(n%10);}while(n /= 10);
			int now = 0, size = V.size();
			for(int i=size-1; i>=0; i--) now *= 10, now += V[i];
			now *= 10, now += m;
			for(int i=0; i<size; i++) now *= 10, now += V[i];
			if(!notP[now] && now >= A && now <= B) Prime.pb(now);
		}
	}
	sort(Prime.begin(), Prime.end());
	for(int x : Prime) printf("%d\n", x); printf("-1");
	return 0;
}










