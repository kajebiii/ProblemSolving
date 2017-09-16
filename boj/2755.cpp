// =====================================================================================
//
//       Filename:  2755.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 15:16:15
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

map<string, double> S;
int main() {
	int N; cin >> N;
	for(char x = 'D'; x >= 'A'; x--)
	{
		string now, ch = " "; ch[0] = x;
	   	now = ch + "+"; S[now] = 'E' - x + 0.3;
	   	now = ch + "0"; S[now] = 'E' - x + 0.0;
	   	now = ch + "-"; S[now] = 'E' - x - 0.3;
	}
	S["F"] = 0.0; 
	int all = 0; double sum = 0;
	for(int i=0; i<N; i++)
	{
		string K; cin >> K;
		int x; string now; scanf("%d", &x); cin >> now;
		all += x;
		sum += 1.0 * x * S[now];
	}
	printf("%.2lf\n", sum / all + 0.00000000001);
	return 0;
}










