#include <stdio.h>
#include <functional>
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
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

char Nr[1111];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	
	while(1)
	{
		scanf("%s", Nr);
		if(Nr[0] == '0') break;
		int N = 0;
		for(int i=0; Nr[i] != 0; i++) N += Nr[i] - '0';
		while(N >= 10)
		{
			int next = 0;
			while(N) next += N % 10, N /= 10;
			N = next;
		}
		printf("%d\n", N);
	}
	return 0;
}