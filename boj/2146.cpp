// =====================================================================================
//
//       Filename:  2146.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/09/2016 10:25:28
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

int UNF[11111], N, Map[111][111];
int F(int v) {return UNF[v]==v?v:UNF[v] = F(UNF[v]);}
void U(int a, int b) {UNF[F(a)] = F(b);}
int main() {
	cin >> N; 
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &Map[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) UNF[i*N+j] = i*N+j;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) for(int k=0; k<4; k++)
		if(Map[i][j] && Map[i+Ch[k].fi][j+Ch[k].se])
			U(i*N+j, (i+Ch[k].fi)*N+j+Ch[k].se);

	int ans = INF;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) 
		for(int x=i; x<=N; x++) for(int y=1; y<=N; y++)
			if(Map[i][j] && Map[x][y] && F(i*N+j) != F(x*N+y))
				ans = min(ans, abs(i-x) + abs(j-y) - 1);
	cout << ans;

	return 0;
}










