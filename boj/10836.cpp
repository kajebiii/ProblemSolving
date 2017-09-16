// =====================================================================================
//
//       Filename:  10836.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 22:38:29
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
const int MAX_N = 777;

int N, T, Nr[MAX_N][MAX_N], Sum[MAX_N], Sum1[MAX_N];
int main() {
	cin >> N >> T;
	for(int t=0; t<T; t++)
	{
		int x = N-1, y = 0;
		for(int i=0; i<3; i++)
		{
			int k; scanf("%d", &k);
			x -= k; if(x < 0) y -= x, x = 0;
			Nr[x][y]++;
			Sum[max(1, y)]++;
		}
	}
	int k = 2*N-1, x = N-1, y = 0;
	while(k--)
	{
		int px = x, py = y;
		x--; if(x<0) y-=x, x=0;
		Nr[x][y] += Nr[px][py];
	}
	
	int plus = 0;
	for(int j=0; j<N; j++)
	{
		plus += Sum[j];
		for(int i=1; i<N; i++) Nr[i][j] += plus;
	}
	for(int i=0; i<N; i++, puts("")) for(int j=0; j<N; j++)
		printf("%d ", Nr[i][j]+1);
	return 0;
}










