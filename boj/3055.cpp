// =====================================================================================
//
//       Filename:  3055.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/04/2016 17:12:56
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

int N, M, Chk[55][55], ChkS[555][55][55];
pi S, D;
char Map[55][55];
int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) scanf("%s", Map[i]+1);
	for(int i=1; i<=N; i++) for(int j=0; j<=M; j++)
		if(Map[i][j] == 'S') S = mp(i, j); else if(Map[i][j] == 'D') D = mp(i, j);
	Map[D.fi][D.se] = Map[S.fi][S.se] = '.';

	int T = 0;
	queue<pi> Q; Q.push(S);
	ChkS[0][S.fi][S.se] = 1;
	while(1)
	{
		++T;
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
			if(i != D.fi || j != D.se) if(Map[i][j] != 'X')
				for(int k=0; k<4; k++)
					if(Map[i+Ch[k].fi][j+Ch[k].se] == '*') 
						Chk[i][j] = T;
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
			if(Chk[i][j] == T) Map[i][j] = '*';

		int plus = 0;
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
			if(Map[i][j] != '*') if(ChkS[T-1][i][j] == 0) if(Map[i][j] != 'X')
				for(int k=0; k<4; k++)
					if(ChkS[T-1][i+Ch[k].fi][j+Ch[k].se] == 1)
						ChkS[T][i][j] = 1, plus++;
		if(plus == 0)
		{
			puts("KAKTUS");
			break;
		}
		if(ChkS[T][D.fi][D.se])
		{
			printf("%d\n", T);
			break;
		}
	}
	return 0;
}










