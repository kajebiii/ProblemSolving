// =====================================================================================
//
//       Filename:  1371.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 01:46:15
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

char A[5555];
int Cnt[26];
int main() {
	while(fgets(A, 5555, stdin))
	{
		for(int i=0; A[i]; i++)
			if(A[i] >= 'a')
				Cnt[A[i]-'a']++;
	}
	int maxV = Cnt[max_element(Cnt, Cnt+26) - Cnt];
	for(int i=0; i<26; i++)
		if(maxV == Cnt[i])
			printf("%c", 'a'+i);
	return 0;
}










