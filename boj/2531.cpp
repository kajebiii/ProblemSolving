// =====================================================================================
//
//       Filename:  2531.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 16:20:00
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
const int MAX_N = 30303;

int N, D, K, C, Nr[MAX_N*2], Cnt[3333];
int main() {
	cin >> N >> D >> K >> C;
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]), Nr[i+N] = Nr[i];

	int Now = 0, Ans = 0;
	for(int i=0; i<K; i++) {Cnt[Nr[i]]++?0:Now++;}
	for(int i=K; i<N+K; i++)
	{
		Cnt[Nr[i]]++?0:Now++;
		--Cnt[Nr[i-K]]?0:Now--;
		Ans = max(Ans, Now + (Cnt[C]==0));
	}
	cout << Ans;
	return 0;
}










