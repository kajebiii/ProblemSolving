// =====================================================================================
//
//       Filename:  5014.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/30/2016 13:47:08
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
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_F = 1e6 + 100;

int Chk[MAX_F];
queue<int> Q;

int main() {
	int F, S, G, U, D; cin >> F >> S >> G >> U >> D;
	Q.push(S); Chk[S] = 1;
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		if(now == G) {printf("%d", Chk[G]-1);break;}
		int C[2] = {+U, -D};
		for(int k=0; k<2; k++)
		{
			int next = now + C[k];
			if(next <= 0 || next > F) continue;
			if(Chk[next] != 0) continue;
			Q.push(next);
			Chk[next] = Chk[now] + 1;
		}
	}
	if(Chk[G] == 0)
		printf("use the stairs");
	return 0;
}










