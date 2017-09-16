// =====================================================================================
//
//       Filename:  7613.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/04/2016 02:19:21
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
const int MAX_N = 111;

struct POINT
{
	double x, y;
	const bool operator<(const POINT& o) const
	{
		if(x == o.x) return y < o.y;
		return x < o.x;
	}
}P[MAX_N];
bool ccw(POINT A, POINT B, POINT C)
{
	double ax = B.x - A.x, ay = B.y - A.y;
	double bx = C.x - B.x, by = C.y - B.y;
	return ax * by - ay * bx > 0;
}
int N, Dy[MAX_N][MAX_N][2];
int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++) scanf("%lf%lf", &P[i].x, &P[i].y);
	sort(P, P+N);

	int ans = 0;
	for(int start=0; start<N; start++)
	{
		for(int i=start; i<N; i++) for(int j=start; j<i; j++)
			Dy[j][i][0] = Dy[j][i][1] = 0;
		for(int i=start+1; i<N; i++) Dy[start][i][0] = Dy[start][i][1] = 1;
		for(int i=start+2; i<N; i++) for(int j=start+1; j<i; j++) for(int k=start; k<j; k++)
			if(ccw(P[k], P[j], P[i]))
				Dy[j][i][0] = max(Dy[j][i][0], (Dy[k][j][0]?Dy[k][j][0]:-INF) + 1);
			else
				Dy[j][i][1] = max(Dy[j][i][1], (Dy[k][j][1]?Dy[k][j][1]:-INF) + 1);
		for(int i=start+1; i<N; i++)
		{
			int maxV[2] = {0, 0};
			for(int j=start; j<i; j++)
				for(int k=0; k<2; k++)
					maxV[k] = max(maxV[k], Dy[j][i][k]);
			ans = max(ans, maxV[0] + maxV[1]);
		}
	}
	cout << ans;
	return 0;
}










