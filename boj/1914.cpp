// =====================================================================================
//
//       Filename:  1914.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 20:19:37
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

int N;
vector<int> Ans;
void findAns(int n, int a, int b)
{
	if(n == 0) return;
	int c = 1+2+3 - a - b;
	findAns(n-1, a, c);
	printf("\n%d %d", a, b);
	findAns(n-1, c, b);
}
int main() {
	cin >> N;
	Ans = vector<int>(100, 0);
	Ans[0] = 1;
	for(int n=1; n<=N; n++)
	{
		for(int i=0; i<99; i++)
			Ans[i] *= 2;
		for(int i=0; i<99; i++) 
			Ans[i+1] += Ans[i]/10, Ans[i]%=10;
	}
	Ans[0]--;
	bool first = false;
	for(int i=99; i>=0; i--)
	{
		if(Ans[i] != 0) first = true;
		if(first) printf("%d", Ans[i]);
	}
	if(N <= 20)
		findAns(N, 1, 3);
	return 0;
}










