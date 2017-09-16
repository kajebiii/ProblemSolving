// =====================================================================================
//
//       Filename:  1662.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/20/2016 12:35:27
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
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

string S; int N;
int Len(int s, int e)
{
	int result = 0;
	for(int i=s; i<=e; i++)
	{
		if(S[i+1] == '(')
		{
			int k = S[i] - '0', nextS = i+1;
			int cnt = 1; i += 1;
			while(cnt > 0)
			{
				i++;
				if(S[i] == '(') cnt++;
				else if(S[i] == ')') cnt--;
			}
			result += k * Len(nextS+1, i-1);
		}
		else result++;
	}
	return result;
}
int main() {
	cin >> S; N = S.length();
	cout << Len(0, N-1);
	return 0;
}










