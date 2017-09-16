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

const int MAX_N = 1e3 + 10;

int Nr[MAX_N], N, S[MAX_N], Go[MAX_N], Chk[MAX_N];
int main() 
{
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]), S[i] = Nr[i];
	sort(S+1, S+N+1);
	for(int i=1; i<=N; i++) Go[i] = lower_bound(S+1, S+N+1, Nr[i]) - S;

	int first = S[1];
	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		if(Chk[i] == 1) continue;
		int now = i, sum = 0, minV = 1e4 + 10, cnt = 0;;
		while(Chk[now] == 0)
		{
			sum += S[now];
			cnt++;
			minV = min(minV, S[now]);
			Chk[now] = 1;
			now = Go[now];
		}
		ans += min(sum + minV * (cnt - 2), sum + minV + first * (cnt + 1));
	}
	cout << ans;
	return 0;
}