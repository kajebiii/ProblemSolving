// =====================================================================================
//
//       Filename:  7579.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 02:47:07
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

int N, M, Ms[111], Cs[111];
int Dy[11111];
int main() {
	cin >> N >> M; 
	for(int i=0; i<N; i++) scanf("%d", &Ms[i]);
	for(int i=0; i<N; i++) scanf("%d", &Cs[i]);
	for(int i=1; i<11111; i++) Dy[i] = -INF;
	for(int i=0; i<N; i++)
	{
		for(int j=11110 - Cs[i]; j>=0; j--)
			if(Dy[j] != -INF)
				Dy[j+Cs[i]] = max(Dy[j+Cs[i]], Dy[j] + Ms[i]);
	}
	for(int i=0; i<11111; i++)
		if(Dy[i] >= M) 
		{
			printf("%d\n", i);
			break;
		}
	return 0;
}










