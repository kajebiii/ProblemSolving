// =====================================================================================
//
//       Filename:  1213.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 18:37:53
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

int Cnt[999];
int main() {
	string S; cin >> S;
	for(char x : S) Cnt[x]++;
	char oddC = 0; int oddCnt = 0;
	for(char x = 'A'; x <= 'Z'; x++)
		if(Cnt[x] % 2) {oddCnt++; oddC = x;}
	if(oddCnt >= 2) {printf("I'm Sorry Hansoo"); return 0;}
	for(char x = 'A'; x <= 'Z'; x++) for(int i=0; i<Cnt[x]/2; i++) printf("%c", x);
	if(oddC != 0) printf("%c", oddC);
	for(char x = 'Z'; x >= 'A'; x--) for(int i=0; i<Cnt[x]/2; i++) printf("%c", x);
	return 0;
}










