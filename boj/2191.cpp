// =====================================================================================
//
//       Filename:  2191.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 22:32:06
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

int N, M, S, K;
vector<int> V[MAX_N];
double G[MAX_N][2], F[MAX_N][2];
bool Visit[MAX_N];
int Match[MAX_N];

bool find_match(int v)
{
	if(Visit[v]) return false;
	Visit[v] = true;
	
	for(int w : V[v])
	{
		if(Match[w] == 0 || find_match(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> N >> M >> S >> K;
	for(int i=1; i<=N; i++) scanf("%lf%lf", &G[i][0], &G[i][1]);
	for(int i=1; i<=M; i++) scanf("%lf%lf", &F[i][0], &F[i][1]);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		double dx = F[j][0] - G[i][0];
		double dy = F[j][1] - G[i][1];
		double dif = dx * dx + dy * dy;
		if(dif <= (double)1.0 * S * S * K * K)
			V[i].push_back(j);
	}
	
	int match = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++) Visit[j] = false;
		if(find_match(i)) match++;
	}

	printf("%d", N - match);
	return 0;
}










