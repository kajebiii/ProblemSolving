// =====================================================================================
//
//       Filename:  7662.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/09/2016 00:41:23
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

int N;
int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("%d", &N);
		multiset<int> S;
		while(N--)
		{
			char t; int x;
			scanf("\n%c %d", &t, &x);
			if(t == 'I') S.insert(x);
			else
			{
				if(S.empty()) continue;
				multiset<int>::iterator it;
				if(x == -1) {it = S.begin();}
				if(x == +1) {it = S.end(); it--;}
				S.erase(it);
			}
		}
		if(S.empty()) puts("EMPTY");
		else
		{
			multiset<int>::iterator it = S.end(); it--;
			printf("%d %d\n", *it, *S.begin());
		}
	}
	return 0;
}










