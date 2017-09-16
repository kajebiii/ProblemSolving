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

char S[99999];
int Cnt[99];
int toInt(char x)
{
	if(x >= 'a' && x <= 'z') x += 'A' - 'a';
	if(x >= 'A' && x <= 'Z') return x - 'A' + 1;
	return 0;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; cin >> TC; scanf("\n");
	for(int t=1; t<=TC; t++)
	{
		fgets(S, 99999, stdin);
		for(int i=0; i<=26; i++) Cnt[i] = 0;
		for(int i=0; S[i] != 0; i++) Cnt[toInt(S[i])]++;
		int ans = INF;
		for(int i=1; i<=26; i++) ans = min(ans, Cnt[i]);
		printf("Case %d: ", t);
		if(ans == 0) puts("Not a pangram");
		else if(ans == 1) puts("Pangram!");
		else if(ans == 2) puts("Double pangram!!");
		else puts("Triple pangram!!!");
	}

	return 0;
}