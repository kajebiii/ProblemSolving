// =====================================================================================
//
//       Filename:  1655.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 16:34:56
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

int N, Median = -INF;
priority_queue<int> MaxQ;
priority_queue<int, vector<int>, greater<int> > MinQ;
int main() {
	cin >> N;
	for(int n=1; n<=N; n++)
	{
		int x; scanf("%d", &x);
		if(Median == -INF) Median = x;
		else
		{
			if(x <= Median) MaxQ.push(x);
			else MinQ.push(x);
			if(MaxQ.size() > MinQ.size())
			{
				MinQ.push(Median);
				Median = MaxQ.top();
				MaxQ.pop();
			}
			else if(MaxQ.size() + 1 < MinQ.size())
			{
				MaxQ.push(Median);
				Median = MinQ.top();
				MinQ.pop();
			}
		}
		printf("%d\n", Median);
	}
	return 0;
}










