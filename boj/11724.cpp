// =====================================================================================
//
//       Filename:  11724.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 16:48:29
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
const int MAX_N = 1e3 + 100;

int UNF[MAX_N];
int F(int v) {return UNF[v]==v?v:UNF[v]=F(UNF[v]);}
void U(int a, int b) {UNF[F(a)] = F(b);}
int N, M;
bool Chk[MAX_N];
int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) UNF[i] = i;
	while(M--)
	{
		int x, y; scanf("%d%d", &x, &y);
		U(x, y);
	}
	int ans = 0;
	for(int i=1; i<=N; i++)
		Chk[F(i)] = true;
	for(int i=1; i<=N; i++) 
		ans += Chk[i];
	cout << ans;
	return 0;
}










