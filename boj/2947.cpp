// =====================================================================================
//
//       Filename:  2947.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 23:12:18
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
	int A[5]; for(int i=0; i<5; i++) cin >> A[i];
	int cnt;
	do
	{
		cnt = 0;
		for(int i=1; i<5; i++)
		{
			if(A[i] > A[i-1]) continue;
			cnt++;
			swap(A[i], A[i-1]);
			for(int j=0; j<5; j++) printf("%d ", A[j]); printf("\n");
		}
	}while(cnt != 0);
	return 0;
}










