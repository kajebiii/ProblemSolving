// =====================================================================================
//
//       Filename:  2303.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 22:21:12
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

struct DATA
{
	int A[5], val, ix, sum;
	const bool operator<(const DATA &o) const
	{
		return val==o.val?ix>o.ix:val>o.val;
	}
}D[1111];
int N;
int main() {
	cin >> N;
	for(int i=0; i<N; i++) for(int j=0; j<5; j++) scanf("%d", &D[i].A[j]);
	for(int i=0; i<N; i++) D[i].sum = accumulate(D[i].A, D[i].A+5, 0);
	for(int i=0; i<N; i++) D[i].val = 0, D[i].ix = i;
	for(int n=0; n<N; n++) for(int i=0; i<5; i++) for(int j=i+1; j<5; j++)
		if(D[n].val < (D[n].sum - D[n].A[i] - D[n].A[j])%10)
			D[n].val = (D[n].sum - D[n].A[i] - D[n].A[j])%10;
	sort(D, D+N);
	printf("%d", D[0].ix+1);
	return 0;
}










