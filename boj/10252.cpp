// =====================================================================================
//
//       Filename:  10252.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 18:20:41
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

int main() {
	int T; cin >> T;
	while(T--)
	{
		int N, M; scanf("%d%d", &N, &M);
		printf("1\n");
		bool odd = false;
		if(N%2) {odd = true; N--; M--;}
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				if(i%2==0)
					printf("(%d,%d)\n", i, j);
				else
					printf("(%d,%d)\n", i, M-1-j);
		if(odd)
		{
			N++;M++;
			for(int i=0; i<M; i++)
				printf("(%d,%d)\n", N-1, i);
			for(int i=N-2; i>=0; i--)
				printf("(%d,%d)\n", i, M-1);
		}
	}
	return 0;
}










