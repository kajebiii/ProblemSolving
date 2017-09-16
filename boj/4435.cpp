// =====================================================================================
//
//       Filename:  4435.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 17:20:05
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

int A[2][8] = { {6, 1, 2, 3, 3, 4, 10, 0}, {7, 1, 2, 2, 2, 3, 5, 10} };
int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++)
	{
		int sum[2] = {0, 0};
		for(int i=0; i<2; i++)
			for(int j=1, x; j<=A[i][0]; j++)
				scanf("%d", &x), sum[i] += x * A[i][j];
		printf("Battle %d: ", t);
		if(sum[0] > sum[1])
			printf("Good triumphs over Evil\n");
		else if(sum[1] > sum[0])
			printf("Evil eradicates all trace of Good\n");
		else
			printf("No victor on this battle field\n");
	}
	return 0;
}










