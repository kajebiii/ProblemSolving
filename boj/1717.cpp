// =====================================================================================
//
//       Filename:  1717.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 14:37:36
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 1e6 + 100;

int UNF[MAX_N];
int F(int v) {return UNF[v] == v ? v : UNF[v] = F(UNF[v]);}
void U(int a, int b) {UNF[F(a)] = F(b);}

int main() {
	int N, M; cin >> N >> M;
	for(int i=0; i<=N; i++) UNF[i] = i;
	while(M--)
	{
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if(t == 0)
			U(a, b);
		else
			if(F(a) == F(b)) puts("YES");
			else puts("NO");
	}
	return 0;
}










