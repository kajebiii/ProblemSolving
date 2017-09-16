// =====================================================================================
//
//       Filename:  1260.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 23:02:14
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

const int MAX_N = 1e3 + 20;

vector<int> V[MAX_N];
int N, M, O;
int Chk[MAX_N];

void DFS(int v)
{
	Chk[v] = 1;
	cout << v << " ";
	for(int w : V[v])
	{
		if(Chk[w] == 1) continue;
		DFS(w);
	}
}

int main() {
	cin >> N >> M >> O;
	for(; M--; )
	{
		int x, y; cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	for(int i=1; i<=N; i++)
		sort(V[i].begin(), V[i].end());

	DFS(O);

	queue<int> Q;
	Q.push(O);
	Chk[O] = 2;
	cout << endl;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		cout << v << " ";
		for(int w : V[v])
		{
			if(Chk[w] == 2) continue;
			Q.push(w);
			Chk[w] = 2;
		}
	}
	
	return 0;
}





















