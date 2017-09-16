// =====================================================================================
//
//       Filename:  2864.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 10:23:47
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

pi get(int k)
{
	vector<int> V;
	for(; k!=0; k/=10)
		V.push_back(k%10);
	int mink=0, maxk=0;
	for(int i=(int)(V.size())-1; i>=0; i--)
	{
		int x = V[i];
		mink *= 10; maxk *= 10;
		mink += x; maxk += x;
		if(x == 5)
			maxk++;
		if(x == 6)
			mink--;
	}
	return mp(mink, maxk);
}

int main() {
	int A, B;
	cin >> A >> B;
	pi AA = get(A), BB = get(B);
	cout << AA.fi + BB.fi << " " << AA.se + BB.se;
	return 0;
}










