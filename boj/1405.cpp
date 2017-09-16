// =====================================================================================
//
//       Filename:  1405.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 14:23:20
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
const pi Ch[4] = {mp(0, -1), mp(0, +1), mp(-1, 0), mp(1, 0)};

double A[4], Ans = 0; int N;
bool Chk[40][40];
void getAns(int n, pi now, double p)
{
	if(n == N)
	{
		Ans += p;
		return;
	}
	for(int i=0; i<4; i++)
	{
		pi next = now + Ch[i];
		if(Chk[next.fi][next.se] == true) continue;
		Chk[next.fi][next.se] = true;
		getAns(n+1, next, p * A[i] / 100);
		Chk[next.fi][next.se] = false;
	}
}
int main() {
	cin >> N; for(int i=0; i<4; i++) scanf("%lf", &A[i]);
	Chk[20][20] = true;
	getAns(0, mp(20, 20), 1);
	printf("%.10lf", Ans);
	return 0;
}










