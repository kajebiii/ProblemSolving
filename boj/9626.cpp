// =====================================================================================
//
//       Filename:  9626.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 21:41:47
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
int main() {
	int M, N; cin >> M >> N;
	int U, L, R, D; cin >> U >> L >> R >> D;
	for(int i=0; i<M; i++) scanf("%s", Map[i]);
	for(int i=0; i<U+D+M; i++, puts("")) for(int j=0; j<L+R+N; j++)
	{
		if(i-U >= 0 && j-L >= 0 && i-U < M && j-L < N)
			printf("%c", Map[i-U][j-L]);
		else
			if((i+j) % 2) printf(".");
			else printf("#");
	}
	return 0;
}










