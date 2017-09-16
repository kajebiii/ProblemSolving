// =====================================================================================
//
//       Filename:  2213.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/20/2016 12:27:30
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
#include <assert.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int N, Nr[11111], Dy[11111][2];
vector<int> V[11111];
void FindDy(int v, int p)
{
	Dy[v][0] = 0; Dy[v][1] = Nr[v];
	for(int w : V[v])
	{
		if(w == p) continue;
		FindDy(w, v);
		Dy[v][0] += max(Dy[w][0], Dy[w][1]);
		Dy[v][1] += Dy[w][0];
	}
}
vector<int> Ans;
void FindAns(int v, int p, int ix)
{
	if(ix == 1) Ans.pb(v);
	for(int w : V[v])
	{
		if(w == p) continue;
		if(ix == 1) FindAns(w, v, 0);
		else if(Dy[w][0] > Dy[w][1]) FindAns(w, v, 0);
		else FindAns(w, v, 1);
	}
}
int main() {
	cin >> N; for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	for(int i=1; i<N; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		V[x].pb(y); V[y].pb(x);
	}
	FindDy(1, 0);
	int maxIx = max_element(Dy[1], Dy[1]+2) - Dy[1];
	printf("%d\n", Dy[1][maxIx]);
	FindAns(1, 0, maxIx);
	sort(Ans.begin(), Ans.end());
	for(int x : Ans) printf("%d ", x);
	return 0;
}










