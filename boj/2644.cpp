// =====================================================================================
//
//       Filename:  2644.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 13:36:17
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

int UNF[111];
int F(int v) {return UNF[v]==0?v:UNF[v]=F(UNF[v]);}
void U(int a, int b) {UNF[F(a)] = F(b);}
int P[111][111];

int main() {
	int N, A, B; cin >> N >> A >> B;
	int M; cin >> M;
	for(; M--; )
	{
		int x, y; scanf("%d%d", &x, &y);
		if(F(x) != F(y))
			U(x, y);
		P[y][1] = x;
	}
	for(int i=1; i<=N; i++)
		P[i][0] = i;
	for(int i=2; i<=N; i++) for(int j=1; j<=N; j++)
		P[j][i] = P[P[j][i-1]][1];
	if(F(A) != F(B))
		puts("-1");
	else
	{
		int ans = INF;
		for(int i=0; i<=N; i++) for(int j=0; j<=N; j++)
			if(P[A][i] == P[B][j] && P[A][i] != 0)
				ans = min(ans, i+j);
		cout << ans;
	}
	return 0;
}










