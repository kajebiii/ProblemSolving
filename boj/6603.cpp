// =====================================================================================
//
//       Filename:  6603.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 00:53:37
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
const int MAX_N = 30;

int Nr[MAX_N];
int C[MAX_N];
int main() {
	int N; bool first = true;
	while(1)
	{
		scanf("%d", &N);
		if(N == 0) break;
		if(!first) printf("\n");
		first = false;
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		for(int i=0; i<6; i++) C[i] = 0;
		for(int i=6; i<N; i++) C[i] = 1;
		do
		{
			for(int i=0; i<N; i++)
				if(C[i] == 0) printf("%d ", Nr[i]);
			printf("\n");
		}while(next_permutation(C, C+N));
	}
	return 0;
}










