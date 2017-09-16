// =====================================================================================
//
//       Filename:  2473.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 12:14:54
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
const int MAX_N = 5555;

int N, Nr[MAX_N];

int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N);

	ll ans = 1ll * INF * INF;
	int ansI = -1, ansJ = -1, ansK = -1;
	for(int i=0; i<N; i++) for(int j=i+1; j<N; j++)
	{
		int k = (int)(lower_bound(Nr+j+1, Nr+N, 0-Nr[i]-Nr[j]) - Nr);
		if(j < k && k < N)
		{
			ll now = abs(1ll * Nr[i] + Nr[j] + Nr[k]);
			if(ans > now) {ans = now, ansI = i, ansJ = j, ansK = k;}
		}
		k--;
		if(j < k && k < N)
		{
			ll now = abs(1ll * Nr[i] + Nr[j] + Nr[k]);
			if(ans > now) {ans = now, ansI = i, ansJ = j, ansK = k;}
		}
	}
	printf("%d %d %d\n", Nr[ansI], Nr[ansJ], Nr[ansK]);
	return 0;
}










