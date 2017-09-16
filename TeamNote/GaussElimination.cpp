#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<double, double> pd;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 5e2 + 10, MAX_M = 5e2 + 10, MOD = 1e9 + 7;

int N, M, Tr[MAX_M], Val[MAX_M]; char S[MAX_N][MAX_M], T[MAX_M];
vector<int> Nr[MAX_M]; // M * [N | M]
bool Free[MAX_N];
int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++) scanf("%s", S[i]);
	for(int i=0; i<M; i++) Nr[i] = vector<int>(N+M, 0);
	for(int i=0; i<M; i++) for(int j=0; j<N; j++) Nr[i][j] = S[j][i] - 'a';
	for(int i=0; i<M; i++) Nr[i][N+i] = 1;

	vector<int> pv;
	for(int j=0; j<N; j++) {
		int ix = -1;
		for(int i=SZ(pv); i<M; i++) if(Nr[i][j] != 0) { ix = i; break; }
		if(ix == -1) continue;
		for(int i=0; i<M; i++) if(i != ix) {
			while(Nr[i][j] != 0) {
				for(int k=0; k<N+M; k++)
					Nr[i][k] = (Nr[i][k] + Nr[ix][k]) % 5;
			}
		}
		swap(Nr[SZ(pv)], Nr[ix]);
		pv.push_back(j);
		//		for(int i=0; i<M; i++, puts("")) for(int j=0; j<N+M; j++) printf("%d ", Nr[i][j]); puts("");
	}

	int Q; cin >> Q;
	ll Ans = 1;
	for(int i=0; i<N-SZ(pv); i++) Ans = Ans * 5 % MOD;
	while(Q--) {
		scanf("%s", T);
		for(int i=0; i<M; i++) Tr[i] = T[i] - 'a', Val[i] = 0;
		for(int i=0; i<M; i++) for(int j=0; j<M; j++)
			Val[i] = (Val[i] + Tr[j] * Nr[i][N+j]) % 5;
		bool isCan = true;
		for(int i=SZ(pv); i<M; i++) if(Val[i] != 0) { isCan = false; break; }
		if(!isCan) puts("0"); else printf("%lld\n", Ans);
	}
	return 0;
}