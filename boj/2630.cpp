// =====================================================================================
//
//       Filename:  2630.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 01:14:19
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

int Cnt[2], Map[999][999];
void getCnt(int a, int b, int k)
{
	bool chk[2] = {false, false};
	for(int i=a; i<a+k; i++) for(int j=b; j<b+k; j++) chk[Map[i][j]] = true;
	if(chk[0] && chk[1])
	{
		for(int i=0; i<2; i++) for(int j=0; j<2; j++)
			getCnt(a+i*(k/2), b+j*(k/2), k/2);
	}
	else
	{
		if(chk[0]) Cnt[0]++;
		if(chk[1]) Cnt[1]++;
	}
}

int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &Map[i][j]);
	getCnt(0, 0, N);
	for(int i=0; i<2; i++) printf("%d\n", Cnt[i]);
	return 0;
}










