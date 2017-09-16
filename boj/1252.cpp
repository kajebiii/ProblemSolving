// =====================================================================================
//
//       Filename:  1252.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 23:05:33
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

int main() {
	string A, B; cin >> A >> B;
	int plus = 0;
	vector<int> V;
	for(int i=0; i<max(A.length(), B.length()); i++)
	{
		int a = i < A.length() ? A[A.length()-1-i]-'0' : 0;
		int b = i < B.length() ? B[B.length()-1-i]-'0' : 0;
		V.push_back((a+b+plus)%2);
		plus = (a+b+plus)/2;
	}
	if(plus) V.push_back(1);
	bool first = false;
	for(int i=(int)V.size()-1; i>=0; i--) 
	{
		if(V[i] != 0) first = true;
		if(first) printf("%d", V[i]);
	}
	if(first == false) printf("0");
	return 0;
}










