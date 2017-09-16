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

typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif

const int INF = 0x7fffffff;

int N; ld Nr[1111][1111];
ld L[1111][1111], U[1111][1111];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N; 
	for(int i=0; i<N; i++) for(int j=0; j<N; j++)
		scanf("%Lf", &Nr[i][j]);
	for(int i=0; i<N; i++) L[i][i] = 1;
	for(int i=0; i<N; i++) U[i][i+1] = Nr[i][i+1];
	U[0][0] = Nr[0][0];
	
	bool noSolve = false;
	for(int i=1; i<N; i++)
	{
		if(U[i-1][i-1] == 0) { noSolve = true; break; }
		L[i][i-1] = Nr[i][i-1] / U[i-1][i-1];
		U[i][i] = Nr[i][i] - L[i][i-1] * U[i-1][i];
	}
	if(noSolve == true) { puts("-1"); return 0; }
	for(int i=0; i<N; i++, puts("")) for(int j=0; j<N; j++) printf("%.3Lf ", L[i][j]);
	for(int i=0; i<N; i++, puts("")) for(int j=0; j<N; j++) printf("%.3Lf ", U[i][j]);
	return 0;
}