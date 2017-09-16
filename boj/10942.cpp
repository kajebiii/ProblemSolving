// =====================================================================================
//
//       Filename:  11046.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 18:45:49
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
const int MAX_N = 2e6 + 200;

int N, M;
int Nr[MAX_N];
int P[MAX_N];

void getP()
{
	int r = 0, p = 0;
	Nr[0] = -1;
	Nr[N+1] = -2;
	for(int i=1; i<=N; i++)
	{
		P[i] = (i <= r)?min(P[p - (i-p)], r-i):0;
		while(Nr[i-P[i]-1] == Nr[i+P[i]+1]) P[i]++;
		if(r < i+P[i]) r = i+P[i], p = i;
	}
}


int main() {
	cin >> N; for(int i=1; i<=N; i++) scanf("%d", &Nr[i*2-1]);
	N = 2*N - 1;
	getP();
	cin >> M;
	while(M--)
	{
		int x, y; scanf("%d%d", &x, &y);
		x = 2*x - 1; y = 2*y - 1;
		if(P[(x+y)/2] * 2 >= (y-x))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}










