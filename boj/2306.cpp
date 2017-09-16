// =====================================================================================
//
//       Filename:  2306.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 22:05:23
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

int Dy[555][555];
int main() {
	string S; cin >> S;
	int N = S.length();
	for(int k=0; k<N; k++)
	{
		for(int i=0; i<N-k; i++)
		{
			int j = i + k;
			if(S[i] == 'a' && S[j] == 't') Dy[i][j] = max(Dy[i][j], Dy[i+1][j-1] + 2);
			if(S[i] == 'g' && S[j] == 'c') Dy[i][j] = max(Dy[i][j], Dy[i+1][j-1] + 2);
			for(int l=i; l<j; l++)
				Dy[i][j] = max(Dy[i][j], Dy[i][l] + Dy[l+1][j]);
		}
	}
	cout << Dy[0][N-1];
	return 0;
}










