// =====================================================================================
//
//       Filename:  1769.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 22:13:39
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
	string S; cin >> S;
	if(S.length() == 1)
	{
		printf("0\n");
		if( (S[0]-'0')%3 == 0 ) puts("YES");
		else puts("NO");
		return 0;
	}
	int sum = 0;
	for(char x : S) sum += x - '0';
	int ans = 1;
	while(sum >= 10)
	{
		int next = 0;
		do{next += sum%10;}while(sum /= 10);
		sum = next;
		ans++;
	}
	printf("%d\n", ans);
	if(sum % 3 == 0) puts("YES");
	else puts("NO");
	return 0;
}










