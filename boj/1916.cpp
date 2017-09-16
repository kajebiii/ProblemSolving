// =====================================================================================
//
//       Filename:  1916.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 17:29:41
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
const int MAX_N = 1e3 + 10;

int N, M;
vector<pi> V[MAX_N];
priority_queue<pi> Q;
int Dy[MAX_N];
bool Chk[MAX_N];

int main() {
	cin >> N >> M;
	for(; M--;)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		V[x].push_back(mp(y, c));
	}
	int A, B; cin >> A >> B;
	for(int i=1; i<=N; i++)
		Dy[i] = INF;
	Dy[A] = 0;
	Q.push(mp(-0, A));
	while(!Q.empty())
	{
		pi temp = Q.top(); Q.pop();
		int now = temp.se, cost = -temp.fi;
		if(Dy[now] < cost) continue;
		for(pi v : V[now])
		{
			int next = v.fi, ncost = cost + v.se;
			if(Dy[next] <= ncost) continue;
			Q.push(mp(-(Dy[next] = ncost), next));
		}
	}
	cout << Dy[B];
	return 0;
}










