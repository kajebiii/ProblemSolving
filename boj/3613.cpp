// =====================================================================================
//
//       Filename:  3613.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 14:43:26
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

int main() {
	string S; cin >> S; int N = S.length();
	int ub = 0, uc = 0;
	for(char x : S)
		if(x == '_') ub++;
		else if(x >= 'A' && x <= 'Z') uc++;
	bool first = (S[0] >= 'a' && S[0] <= 'z');
	bool last = (S[N-1] != '_');
	bool notTwo = true;
	for(int i=0; i<N-1; i++)
		if(S[i] == '_' && S[i+1] == '_') notTwo = false;
	if(first && uc == 0 && last && notTwo)
	{
		for(int i=0; i<N; i++)
		{
			if(S[i] == '_') {S[i+1] += 'A' - 'a'; continue;}
			printf("%c", S[i]);
		}
	}
	else if(first && ub == 0)
	{
		for(int i=0; i<N; i++)
		{
			if(S[i] >= 'A' && S[i] <= 'Z') {printf("_"); S[i] -= 'A' - 'a';}
			printf("%c", S[i]);
		}
	}
	else puts("Error!");
	return 0;
}










