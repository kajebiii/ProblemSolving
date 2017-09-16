// =====================================================================================
//
//       Filename:  1199.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 23:09:56
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
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int V[1111][1111], sum = 0, N, Cnt[1111];
vector<int> Ans;
void Find(int v)
{
	for(int i=Cnt[v]; i<=N;)
	{
		Cnt[v] = i;
		if(V[v][i] == 0) {i++; continue;}
		V[v][i]--; V[i][v]--; sum -= 2;
		Find(i);
	}
	Ans.pb(v);
}
int main() {
	cin >> N; 
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) 
		scanf("%d", &V[i][j]), sum += V[i][j];
	for(int i=1; i<=N; i++)
	{
		Cnt[i] = 1;
		int now = 0;
		for(int j=1; j<=N; j++) now += V[i][j];
		if(now % 2 == 1) {puts("-1"); return 0;}
	}
	Find(1);
	if(sum != 0) printf("-1");
	else for(int x : Ans) printf("%d ", x);
	return 0;
}










