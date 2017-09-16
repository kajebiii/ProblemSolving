// =====================================================================================
//
//       Filename:  2160.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 21:15:51
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

char Map[55][5][7];
int main() {
	int N; cin >> N;
	for(int n=0; n<N; n++) for(int i=0; i<5; i++) scanf("%s", Map[n][i]);

	int MinVal = INF, MinI = -1, MinJ = -1;
	for(int i=0; i<N; i++) for(int j=i+1; j<N; j++)
	{
		int cnt = 0;
		for(int x=0; x<5; x++) for(int y=0; y<7; y++)
			if(Map[i][x][y] != Map[j][x][y]) cnt++;
		if(MinVal > cnt) {MinVal = cnt, MinI = i, MinJ = j;}
	}
	cout << MinI+1 << ' ' << MinJ+1;
	return 0;
}










