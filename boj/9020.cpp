// =====================================================================================
//
//       Filename:  6588.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 19:53:35
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
#define fi first
#define se second
#define pb push_back

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

bool notP[11111];
vector<int> P;
pi Ans[11111];

int main() {
	for(int i=2, j; i<=10000; i++)
		if(notP[i] == false) for(j=i*2, P.pb(i); j<=10000; j+=i) notP[j] = true;
	notP[1] = true;
	for(int i=4; i<=10000; i+=2)
		for(int x : P)
		{
			if(i-x < x) break;
			if(i-x >= 2 && notP[i-x] == false)
				{Ans[i] = mp(x, i-x);}
		}
	int T; cin >> T;
	while(T--)
	{
		int N; scanf("%d", &N);
		printf("%d %d\n", Ans[N].fi, Ans[N].se);
	}
	return 0;
}










