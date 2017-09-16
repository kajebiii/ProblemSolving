// =====================================================================================
//
//       Filename:  9184.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 15:02:41
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

int Dy[30][30][30];
int get(int a, int b, int c)
{
	if(a<=0 || b<=0 || c<=0) return 1;
	if(a>20 || b>20 || c>20) return get(20, 20, 20);
	if(Dy[a][b][c] != INF) return Dy[a][b][c];
	int ans;
	if(a<b && b<c) ans = get(a, b, c-1) + get(a, b-1, c-1) - get(a, b-1, c);
	else ans = get(a-1, b, c) + get(a-1, b-1, c) + get(a-1, b, c-1) - get(a-1, b-1, c-1);
	Dy[a][b][c] = ans;
	return ans;
}
int main() {	
	for(int i=0; i<=20; i++) for(int j=0; j<=20; j++) for(int k=0; k<=20; k++)
		Dy[i][j][k] = INF;
	int a, b, c; while(scanf("%d%d%d", &a, &b, &c))
	{
		if(a == -1 && b == - 1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, get(a, b, c));
	}
	return 0;
}










