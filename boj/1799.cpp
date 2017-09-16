// =====================================================================================
//
//       Filename:  1799.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 20:00:36
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

int N, Visit[99], Match[99];
vector<int> V[99];

bool findMatch(int v)
{
	if(Visit[v] == 1) return false;
	Visit[v] = 1;

	for(int w : V[v])
		if(Match[w] == -1 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}
int main() {
	cin >> N;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++)
	{
		int x; scanf("%d", &x);
		if(x == 0) continue;
		V[i+j].pb(i-j+N-1);
	}
	int Ans = 0;
	for(int i=0; i<2*N; i++) Match[i] = -1;
	for(int i=0; i<2*N; i++)
	{
		for(int j=0; j<2*N; j++) Visit[j] = 0;
		if(findMatch(i))
			Ans++;
	}
	cout << Ans;
	return 0;
}










