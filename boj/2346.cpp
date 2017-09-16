// =====================================================================================
//
//       Filename:  2346.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 18:00:01
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
const int MAX_N = 1111;

int N, Nr[MAX_N], Go[MAX_N][2];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	for(int i=0; i<N; i++) Go[i][0] = (i+N-1)%N, Go[i][1] = (i+1)%N;
	int now = 0, cnt = 0;
	while(true)
	{
		printf("%d ", now+1);
		cnt++;
		if(cnt == N) break;
		Go[Go[now][1]][0] = Go[now][0];
		Go[Go[now][0]][1] = Go[now][1];
		int next = now;
		for(int i=0; i<Nr[now]; i++) next = Go[next][1];
		for(int i=0; i>Nr[now]; i--) next = Go[next][0];
		now = next;
	}
	return 0;
}










