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

const int MAX_N = 1e2 + 30, MAX_L = 88;

int N, M, K, L;
char Map[MAX_N][MAX_N];
string S;
int Dy[MAX_L][MAX_N][MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for(int i=0; i<N; i++) scanf("%s", Map[i]);
	cin >> S;
	L = S.length();
	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
		if(Map[i][j] == S[0]) Dy[0][i][j] = 1;
	for(int p=1; p<L; p++)
	{
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(Map[i][j] == S[p])
			for(int k=0; k<4; k++) for(int l=1; l<=K; l++)
			{
				int a = i + Ch[k].fi * l;
				int b = j + Ch[k].se * l;
				if(a < 0 || a >= N || b < 0 || b >= M) continue;
				if(Map[a][b] != S[p-1]) continue;
				Dy[p][i][j] += Dy[p-1][a][b];
			}
	}

	int ans = 0;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
		ans += Dy[L-1][i][j];

	cout << ans;
	return 0;
}