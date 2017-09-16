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
const pi Ch[8] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(-1, 1), mp(1, -1), mp(1, 1) };

const int MAX_N = 22;

int N, L, Nr[MAX_N][MAX_N];
ll Dy[MAX_N][MAX_N*MAX_N][MAX_N*MAX_N];

int toInt(pi x) { return x.fi*N + x.se; }
pi toPair(int x) { return mp(x/N, x%N); }
bool isIn(pi x) { return !(x.fi < 0 || x.se < 0 || x.fi >= N || x.se >= N); }

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> L;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &Nr[i][j]);
	if(L % 2 == 0)
		for(int i=0; i<N; i++) for(int j=0; j<N; j++)
		{
			pi a = mp(i, j);
			for(int k=0; k<8; k++)
			{
				pi b = a + Ch[k];
				if(isIn(b) == false) continue;
				if(Nr[a.fi][a.se] != Nr[b.fi][b.se]) continue;
				Dy[2][toInt(a)][toInt(b)] = 1;
				Dy[2][toInt(b)][toInt(a)] = 1;
			}
		}
	else
		for(int i=0; i<N; i++) for(int j=0; j<N; j++)
			Dy[1][toInt(mp(i, j))][toInt(mp(i, j))] = 1;

	for(int p=4-L%2; p<=L; p+=2)
		for(int x=0; x<N*N; x++) for(int y=0; y<N*N; y++)
		{
			pi a = toPair(x), b = toPair(y);
			if(Nr[a.fi][a.se] != Nr[b.fi][b.se]) continue;
			for(int k=0; k<8; k++) for(int l=0; l<8; l++)
			{
				pi na = a + Ch[k], nb = b + Ch[l];
				if(isIn(na) == false || isIn(nb) == false) continue;
				Dy[p][toInt(a)][toInt(b)] += Dy[p-2][toInt(na)][toInt(nb)];
			}
		}
	ll sum = 0;
	for(int x=0; x<N*N; x++) for(int y=0; y<N*N; y++)
		sum += Dy[L][x][y];
	cout << sum;
	return 0;
}