// =====================================================================================
//
//       Filename:  11067.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 01:23:57
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
pi Nr[101101];
int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d%d", &Nr[i].fi, &Nr[i].se);
		sort(Nr, Nr+N);
		int meet = 0;
		for(int i=0; i<N; i++)
		{
			int j = i;
			while(Nr[j+1].fi == Nr[i].fi) j++;
			if(Nr[j].se == meet) reverse(Nr+i, Nr+j+1);
			meet = Nr[j].se;
			i = j;
		}
		int M; scanf("%d", &M);
		while(M--)
		{
			int x; scanf("%d", &x);
			printf("%d %d\n", Nr[x-1].fi, Nr[x-1].se);
		}
	}
	return 0;
}










