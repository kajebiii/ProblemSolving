// =====================================================================================
//
//       Filename:  2696.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/21/2016 22:47:32
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
#include <assert.h>

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

int N;
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		priority_queue<int, vector<int>, greater<int> > MaxQ;
		priority_queue<int> MinQ;
		MinQ.push(-INF-1); MaxQ.push(INF);
		scanf("%d", &N); printf("%d", (N+1)/2);
		for(int i=0; i<N; i++)
		{
			int x; scanf("%d", &x);
			int a = MinQ.top(), b = MaxQ.top();
			if(x < b) MinQ.push(x);
			else MaxQ.push(x);
			if(MinQ.size() > MaxQ.size() + 1) {MaxQ.push(MinQ.top()); MinQ.pop();}
			if(MaxQ.size() > MinQ.size()    ) {MinQ.push(MaxQ.top()); MaxQ.pop();}
			if(i % 20 == 0) printf("\n");
			if(i % 2 == 0) printf("%d ", MinQ.top());
		}
		puts("");
	}
	return 0;
}










