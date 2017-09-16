// =====================================================================================
//
//       Filename:  10159.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 13:45:12
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
const int MAX_N = 111;

vector<int> V[MAX_N];
int Chk[MAX_N], S[MAX_N];
int N, M;

int main() {
	cin >> N >> M;
	for(; M--; )
	{
		int x, y;
		scanf("%d%d", &x, &y);
		V[x].push_back(y);
	}
	for(int i=1; i<=N; i++)
	{
		queue<int> Q;
		Q.push(i);
		Chk[i] = i;
		while(!Q.empty())
		{
			int now = Q.front(); Q.pop();
			if(i != now) S[now]++;
			S[i]++;
			for(int x : V[now])
			{
				if(Chk[x] == i) continue;
				Q.push(x);
				Chk[x] = i;
			}
		}
	}
	for(int i=1; i<=N; i++)
		printf("%d\n", N - S[i]);
	return 0;
}










