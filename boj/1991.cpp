// =====================================================================================
//
//       Filename:  1991.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 14:20:50
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

int N;
vector<int> V[200];

void DFS(int x, int v)
{
	if(x == '.') return;
	if(v == 0) cout << (char)x;
	DFS(V[x][0], v);
	if(v == 1) cout << (char)x;
	DFS(V[x][1], v);
	if(v == 2) cout << (char)x;
}

int main() {
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		char x; cin >> x;
		for(int j=0; j<2; j++)
		{
			char y; cin >> y;
			V[x].push_back(y);
		}
	}
	DFS('A', 0); puts("");
	DFS('A', 1); puts("");
	DFS('A', 2); puts("");
	return 0;
}










