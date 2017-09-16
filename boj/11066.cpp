// =====================================================================================
//
//       Filename:  11066.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 18:49:50
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
const int MAX_N = 555;

int N, Dy[MAX_N][MAX_N], Nr[MAX_N], Sum[MAX_N];
int K[MAX_N][MAX_N];
int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
		for(int i=1; i<=N; i++) Sum[i] = Sum[i-1] + Nr[i];
		for(int i=1; i<N; i++) for(int j=i+1; j<=N; j++) Dy[i][j] = INF;
		for(int i=1; i<=N; i++) K[i][i] = i;
		for(int k=1; k<N; k++)
			for(int i=1; i<=N-k; i++)
			{
				int j = i + k;
				for(int l=max(K[i][j-1]-5, i); l<min(K[i+1][j]+5, j); l++)
				{
					int now = Dy[i][l] + Dy[l+1][j] + Sum[j] - Sum[i-1];
					if(Dy[i][j] > now)
					{
						Dy[i][j] = now;
						K[i][j] = l;
					}
				}
			}
		printf("%d\n", Dy[1][N]);
	}
	return 0;
}










