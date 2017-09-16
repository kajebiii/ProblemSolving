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

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

int N, M, Nr[111], Dy[111][22], P[111][22];
void getAns(int n, int m)
{
	if(P[n][m] == 0) return;
	getAns(P[n][m], m-1);
	printf("%d ", P[n][m]);
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> M; M += 1;
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	for(int i=0; i<=N; i++) for(int j=0; j<=M; j++) Dy[i][j] = INF;
	Dy[0][0] = 0;
	for(int i=1; i<=N; i++)
	{
		int now = 0, sum = 0;
		for(int j=i; j<=N; j++)
		{
			sum += Nr[j] * now;
			now += Nr[j];
			for(int k=1; k<=M; k++)
				if(Dy[i-1][k-1] != INF && Dy[j][k] > Dy[i-1][k-1] + sum)
					Dy[j][k] = Dy[i-1][k-1] + sum, P[j][k] = i-1;
		}
		if(debug) for(int j=0; j<=M; j++) printf("%d %d : %d\n", i, j, Dy[i][j]);
	}
	int ans = Dy[N][M];
	cout << ans << endl;
	getAns(N, M);
	return 0;
}