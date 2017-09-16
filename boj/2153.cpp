// =====================================================================================
//
//       Filename:  2153.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 12:50:10
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

int CtoI(char x)
{
	if(x >= 'a') return x - 'a' + 1;
	return x - 'A' + 27;
}

int main() {
	int sum = 0;
	string S; cin >> S;
	for(char x : S) sum += CtoI(x);

	bool isPrime = true;
	for(int i=2; i*i<=sum; i++)
		if(sum % i == 0) isPrime = false;
	if(isPrime)
		puts("It is a prime word.");
	else
		puts("It is not a prime word.");
	return 0;
}










