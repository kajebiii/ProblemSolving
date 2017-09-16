// =====================================================================================
//
//       Filename:  9019.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 02:17:38
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

char C[4] = {'D', 'S', 'L', 'R'};
int D[10000], T[10000], B[10000];
void getAns(int n)
{
	if(B[n] < 0) return;
	getAns(B[n]);
	printf("%c", C[T[n]]);
}
int main() {
	int Test; cin >> Test;
	while(Test--)
	{
		int X, Y; scanf("%d%d", &X, &Y);
		for(int i=0; i<10000; i++) D[i] = INF;
		queue<int> Q;
		Q.push(X); D[X] = 0; B[X] = -1;
		while(!Q.empty())
		{
			int now = Q.front(), t; Q.pop();
			if(now == Y) break;
			t = now * 2 % 10000;
			if(D[t] == INF) {D[t] = D[now]+1; T[t] = 0; Q.push(t); B[t] = now;}
			t = (now + 9999) % 10000;
			if(D[t] == INF) {D[t] = D[now]+1; T[t] = 1; Q.push(t); B[t] = now;}
			t = (now * 10 + now / 1000) % 10000;
			if(D[t] == INF) {D[t] = D[now]+1; T[t] = 2; Q.push(t); B[t] = now;}
			t = (now / 10 + now % 10 * 1000) % 10000;
			if(D[t] == INF) {D[t] = D[now]+1; T[t] = 3; Q.push(t); B[t] = now;}
		}
		getAns(Y);
		printf("\n");
	}
	return 0;
}










