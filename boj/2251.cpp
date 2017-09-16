// =====================================================================================
//
//       Filename:  2251.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 01:28:07
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
#ifdef ONLINE_JUDGE
const bool debug = false;
#else
const bool debug = true;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int W[3];
bool isCan[201][201][201];
void findCan(int a, int b, int c)
{
	if(isCan[a][b][c] == true) return;
	if(debug) printf("%d %d %d\n", a, b, c);
	isCan[a][b][c] = true;
	int D[3] = {a, b, c};
	int E[3] = {0};
	for(int i=0; i<3; i++) for(int j=0; j<3; j++)
	{
		if(i == j) continue;
		for(int k=0; k<3; k++) E[k] = D[k];
		E[j] += E[i];
		if(E[j] > W[j]) {E[i] = E[j] - W[j]; E[j] = W[j];}
		else E[i] = 0;
		findCan(E[0], E[1], E[2]);
	}
	return;
}
int main() {
	for(int i=0; i<3; i++) cin >> W[i];
	findCan(0, 0, W[2]);
	for(int i=0; i<=W[2]; i++) for(int j=0; j<=W[1]; j++)
		if(isCan[0][j][i] == true) {printf("%d ", i); break;}
	return 0;
}










