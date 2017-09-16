// =====================================================================================
//
//       Filename:  2018.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/09/2016 12:36:47
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
bool Check(int x, int y)
{
	int a = (x - y + 1) / 2;
	int n = y;
	if(a >= 1 && n >= 1) return true;
	return false;
}
int main() {
	cin >> N; N *= 2;
	int power = 1;
	while(N % 2 == 0) power *= 2, N /= 2;

	int ans = 0;
	for(int i=1; i*i<=N; i++)
	{
		if(N%i != 0) continue;
		int j = N/i;
		ans += Check(i * power, j);
		ans += Check(i, j * power);
		if(i != j)
		{
			ans += Check(j * power, i);
			ans += Check(j, i * power);
		}
	}
	cout << ans;
	return 0;
}










