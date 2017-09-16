// =====================================================================================
//
//       Filename:  2661.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 13:45:09
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

int N, Nr[88];
bool findAns = false;
void find(int n)
{
	if(n == N)
	{
		findAns = true;
		for(int i=0; i<N; i++) printf("%d", Nr[i]);
		return;
	}
	for(int i=0; i<3; i++)
	{
		bool isCan = true;
		Nr[n] = i+1;
		for(int j=1; j<=(n+1)/2; j++)
		{
			bool nowCan = false;
			for(int k=0; k<j; k++)
				if(Nr[n-j-j+1+k] != Nr[n-j+1+k])
					nowCan = true;
			if(nowCan == false) isCan = false;
		}
		if(isCan == false) continue;
		find(n+1);
		if(findAns) return;
		Nr[n] = 0;
	}
}
int main() {
	cin >> N;
	find(0);
	return 0;
}










