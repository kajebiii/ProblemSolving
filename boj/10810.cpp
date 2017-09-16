// =====================================================================================
//
//       Filename:  10810.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 17:19:09
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
const int MAX_N = 111;

int N, M;
int UNF[MAX_N];
int F(int v) {return UNF[v] == v ? v : UNF[v] = F(UNF[v]);}

int Data[MAX_N][3];
int Ans[MAX_N];
int main() {
	cin >> N >> M;
	for(int i=M; i>=1; i--) scanf("%d%d%d", &Data[i][0], &Data[i][1], &Data[i][2]);
	for(int i=1; i<=N+1; i++) UNF[i] = i;
	for(int i=1; i<=M; i++)
	{
		int a = Data[i][0], b = Data[i][1], c = Data[i][2];
		for(int j=F(a); j<=b; j = UNF[j] = F(j+1)) Ans[j] = c;
	}
	for(int i=1; i<=N; i++) printf("%d ", Ans[i]);
	return 0;
}










