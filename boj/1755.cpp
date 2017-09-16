// =====================================================================================
//
//       Filename:  1755.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 15:05:16
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

map<string, int> Map;
string Eng[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string makeS(int v)
{
	if(v == 0) return "";
	return makeS(v/10) + Eng[v%10];
}
int main() {
	int N, M; cin >> N >> M; if(N > M) swap(N, M);
	for(int i=N; i<=M; i++)
	{
		string S = makeS(i);
		Map[S] = i;
	}
	int cnt = 0;
	for(auto x : Map)
		printf("%d%c", x.se, ++cnt%10?' ':'\n');
	return 0;
}










