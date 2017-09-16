// =====================================================================================
//
//       Filename:  7490.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  10/04/2016 15:46:52
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
#include <assert.h>

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
const pi Ch[8] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(-1, 1), mp(1, -1), mp(1, 1)};

int N;
int Set[99];
int main() {
	int TC; cin >> TC;
	for(int t=0; t<TC; t++)
	{
		if(t > 0) puts("");
		int power = 1;
		cin >> N;
		for(int i=0; i<N-1; i++) power *= 3;
		Set[0] = 1;
		for(int p=0; p<power; p++)
		{
			int temp = p;
			for(int i=N-1; i>=1; i--) Set[i] = temp % 3, temp /= 3;
			
			int now = 0, multi = 0, result = 0;
			for(int i=1; i<=N; i++)
			{
				if(Set[i-1] != 0) result += multi * now;
				if(Set[i-1] == 1) multi = +1, now = i;
				if(Set[i-1] == 2) multi = -1, now = i;
				if(Set[i-1] == 0)
				{
					now *= 10;
					now += i;
				}
			}
			result += now * multi;
			if(result == 0)
				for(int i=1; i<=N; i++)
				{
					if(i != 1) printf("%c", Set[i-1]==0?' ':Set[i-1]==1?'+':'-');
					printf("%d", i);
					if(i == N) puts("");
				}
		}
	}
	return 0;
}










