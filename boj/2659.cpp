// =====================================================================================
//
//       Filename:  2659.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 17:15:00
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
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int Nr[11111];
int Watch(int n)
{
	int A[7]; for(int i=3; i>=0; i--) A[i] = n%10, n/=10;
	for(int i=4; i<7; i++) A[i] = A[i-4];
	int now = 0;

	int result = INF;
	for(int i=0; i<7; i++)
	{
		now -= now / 1000 * 1000;
		now *= 10; now += A[i];
		if(i >= 3) result = min(result, now);
	}
	return result;
}
int main() {
	int cnt = 0;
	for(int i=1; i<10; i++) for(int j=1; j<10; j++)
		for(int k=1; k<10; k++) for(int l=1; l<10; l++)
		{
			int now = i*1000 + j*100 + k*10 + l;
			if(Watch(now) == now)
				Nr[now] = ++cnt;
		}
	int A[4]; for(int i=0; i<4; i++) scanf("%d", &A[i]);
	printf("%d", Nr[Watch(A[0]*1000+A[1]*100+A[2]*10+A[3])]);
	return 0;
}










