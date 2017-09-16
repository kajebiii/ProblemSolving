// =====================================================================================
//
//       Filename:  11657.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/07/2016 21:46:19
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

int N, M;
vector<pi> V[555];
bool Visit[555], Update[555]; int Dis[555];
int main() {
	cin >> N >> M;
	while(M--)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		V[x].pb(mp(y, c));
	}
	
	for(int i=1; i<=N; i++) Dis[i] = INF;
	Visit[1] = true; Dis[1] = 0;
	for(int k=1; k<=N; k++)
	{
		for(int i=1; i<=N; i++) for(pi x : V[i])
		{
			if(Visit[i] == false) continue;
			if(Dis[x.fi] > Dis[i] + x.se)
			{
				Dis[x.fi] = min(Dis[x.fi], Dis[i] + x.se);
				Visit[x.fi] = true;
				Update[k] = true;
			}
		}
	}
	if(Update[N] == true) {printf("-1\n"); return 0;}

	for(int i=2; i<=N; i++)
		if(Visit[i] == false) printf("-1\n");
		else printf("%d\n", Dis[i]);
	return 0;
}










