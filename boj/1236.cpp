// =====================================================================================
//
//       Filename:  1236.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 15:24:22
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

char Map[55][55];
bool Chk[2][55];
int main() {
	int N, M; cin >> N >> M;
	for(int i=1; i<=N; i++) scanf("%s", Map[i]+1);
	int A = 0,  B = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		if(Map[i][j] == '.') continue;
		if(Chk[0][i] == false) {Chk[0][i] = true; A++;}
		if(Chk[1][j] == false) {Chk[1][j] = true; B++;}
	}
	cout << max(N-A, M-B);
	return 0;
}










