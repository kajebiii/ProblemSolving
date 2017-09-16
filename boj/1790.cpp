// =====================================================================================
//
//       Filename:  1748.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 16:24:40
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
	int N, K; cin >> N >> K;
	int power = 10, cnt = 1;
	int ans = 0; bool flag = true;
	while(1)
	{
		int past = ans;
		ans += min(power - power/10, N - power/10 + 1) * cnt;
		if(K <= ans)
		{
			int ansIx = (K - past - 1) / cnt + power/10;
			int index = cnt - (K - past - 1) % cnt - 1;
			int p = 1; for(int i=0; i<index; i++) p *= 10;
			printf("%d", ansIx%(p*10)/p);
			flag = false;
			break;
		}
		if(N < power) break;
		power *= 10;
		cnt++;
	}
	if(flag) printf("-1");
	return 0;
}










