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
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }


int N, K;
int Ch[26], Can[22];
string S[55];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for(int i=0; i<N; i++) cin >> S[i];
	if(K < 5) { puts("0"); return 0; }
	K -= 5;
	for(int i=0, cnt=0; i<26; i++)
	{
		char now = 'a' + i;
		if(now == 'a' || now == 'n' || now == 't' || now == 'i' || now == 'c')
			Ch[i] = 21;
		else
			Ch[i] = cnt++;
	}
	Can[21] = 1;

	for(int i=21-K; i<21; i++) Can[i] = 1;
	int ans = 0;
	do
	{
		int cnt = 0;
		for(int i=0; i<N; i++)
		{
			bool isCan = true;
			for(int j=4; j<(int)S[i].length()-4; j++)
				if(Can[Ch[S[i][j]-'a']] == 0) isCan = false;
			if(isCan) cnt++;
		}
		ans = max(ans, cnt);
	} while(next_permutation(Can, Can+21));
	printf("%d\n", ans);
	return 0;
}