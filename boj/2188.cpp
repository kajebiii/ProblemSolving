// =====================================================================================
//
//       Filename:  2188.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 15:30:52
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
#define pb push_back
#define fi first
#define se second
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 222;

int N, M;
vector<int> V[MAX_N];
bool Visit[MAX_N];
int Match[MAX_N];

bool findMatch(int v)
{
	if(Visit[v]) return false;
	Visit[v] = true;

	for(int w : V[v])
	{
		if(Match[w] == 0 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	}
	return false;
}
int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		int K; scanf("%d", &K);
		while(K--)
		{
			int x; scanf("%d", &x);
			V[i].push_back(x);
		}
	}

	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++) Visit[j] = false;
		if(findMatch(i)) ans++;
	}
	cout << ans;
	return 0;
}










