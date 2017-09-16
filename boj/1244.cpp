// =====================================================================================
//
//       Filename:  1244.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 20:07:47
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

int N, Nr[111];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	int Q; cin >> Q;
	while(Q--)
	{
		int t, x; scanf("%d%d", &t, &x);
		if(t == 1) for(int i=x-1; i<N; i+=x) Nr[i] = 1 - Nr[i];
		else
		{
			int i = x-1;
			int a = 0;
			while(i-a >= 0 && i+a < N && Nr[i-a] == Nr[i+a]) 
				Nr[i-a] = Nr[i+a] = 1 - Nr[i-a], a++;
		}
	}
	for(int i=0; i<N; i++) 
	{
		if(i > 0 && i % 20 == 0) puts("");
		printf("%d ", Nr[i]);
	}
	return 0;
}










