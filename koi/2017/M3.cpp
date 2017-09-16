#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 100;

int N, M, S[MAX_N], Cnt[MAX_N];
int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++) S[i] = i;
	for(int i=0; i<M; i++) {
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		if(x > y) swap(x, y);
		S[x]++; S[y]--;
	}
	for(int i=0; i<N; i++) Cnt[S[i]]++;
	for(int i=0; i<N; i++) if(Cnt[i] != 1) {puts("-1"); return 0;}
	for(int i=0; i<N; i++) printf("%d ", S[i] + 1); puts("");
	return 0;
}