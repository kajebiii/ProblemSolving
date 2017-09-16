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

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

bool notP[1111111];
vector<int> P;
pi Ans[1111111];

int main() {
	for(int i=2, j; i<=1000000; i++)
		if(notP[i] == false) for(j=i*2, P.push_back(i); j<=1000000; j+=i) notP[j] = true;
	for(int i=6; i<=1000000; i+=2)
		for(int x : P)
			if(i-x > 2 && notP[i-x] == false)
			{Ans[i] = mp(x, i-x);break;}
	notP[1] = true;
	int n;
	while(scanf("%d", &n))
	{
		if(n == 0) break;
		printf("%d = %d + %d\n", n, Ans[n].fi, Ans[n].se);
	}
	return 0;
}










