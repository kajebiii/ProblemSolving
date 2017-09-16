// =====================================================================================
//
//       Filename:  11502.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 16:21:13
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

bool notP[1111];
pi Ans[1111];
int main() {
	int T; cin >> T;
	notP[1] = notP[0] = true;
	for(int i=2; i<=1000; i++) if(notP[i] == false)
		for(int j=i*2; j<=1000; j+=i) notP[j] = true;
	for(int i=4; i<=1000; i++)
		for(int j=2; j<i; j++)
			if(notP[j] == false && notP[i-j] == false)
				Ans[i].fi = j, Ans[i].se = i-j;
	while(T--)
	{
		int N; scanf("%d", &N);
		if(N == 5) {printf("0\n"); continue;}
		int A[3] = {0, 0, 3};
		A[0] = Ans[N-3].fi, A[1] = Ans[N-3].se;
		sort(A, A+3);
		for(int i=0; i<3; i++) printf("%d ", A[i]); printf("\n");
	}
	return 0;
}










