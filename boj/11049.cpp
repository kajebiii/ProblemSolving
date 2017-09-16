// =====================================================================================
//
//       Filename:  11049.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 02:35:15
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

int Nr[555][2], N, Dy[555][555];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d%d", &Nr[i][0], &Nr[i][1]);
	for(int i=0; i<N; i++) for(int j=0; j<i; j++)
		Dy[j][i] = INF;
	for(int i=0; i<N; i++) for(int j=i-1; j>=0; j--) for(int k=j; k<i; k++)
		Dy[j][i] = min(Dy[j][i], Dy[j][k] + Dy[k+1][i] + Nr[j][0]*Nr[k][1]*Nr[i][1]);
	cout << Dy[0][N-1];
	return 0;
}










