// =====================================================================================
//
//       Filename:  2580.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 15:19:08
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

int Nr[9][9];
int R[9][10], C[9][10], G[9][10];
int getG(int a, int b) {return a/3*3+b/3;}
bool Find = false;
void getAns(int a, int b)
{
	if(a == 9)
	{
		Find = true;
		for(int i=0; i<9; i++, puts(""))
			for(int j=0; j<9; j++)
				printf("%d", Nr[i][j]);
		return;
	}
	if(b == 9) return getAns(a+1, 0);
	if(Nr[a][b] != 0) return getAns(a, b+1);
	for(int i=1; i<=9; i++)
	{
		if(R[a][i] == 1) continue;
		if(C[b][i] == 1) continue;
		if(G[getG(a,b)][i] == 1) continue;
		R[a][i] = 1;
		C[b][i] = 1;
		G[getG(a,b)][i] = 1;
		Nr[a][b] = i;
		getAns(a, b+1);
		Nr[a][b] = 0;
		if(Find) return;
		R[a][i] = 0;
		C[b][i] = 0;
		G[getG(a,b)][i] = 0;
	}
}
int main() {
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) scanf("%1d", &Nr[i][j]);
	for(int i=0; i<9; i++) for(int j=0; j<9; j++)
	{
		if(Nr[i][j] == 0) continue;
		int x = Nr[i][j];
		R[i][x] = 1;
		C[j][x] = 1;
		G[getG(i, j)][x] = 1;
	}
	getAns(0, 0);
	return 0;
}










