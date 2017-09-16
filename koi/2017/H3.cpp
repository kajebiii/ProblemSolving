#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, int> pli; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 3e3 + 100, MAX_M = 3e3 + 100;

int N, M, S, E, T;
int Nr[MAX_N][MAX_M], Sum[MAX_N][MAX_M], Dy[MAX_N][MAX_M];
bool nVis[MAX_N][MAX_N];
int getSum(int ix, int a, int b) {return Sum[ix][b] - Sum[ix][a-1];}
deque<pi> minV[MAX_N];
int main() {
	cin >> N >> M >> S >> E >> T;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &Nr[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=M+10; j++) Sum[i][j] = Sum[i][j-1] + Nr[i][j];
	for(int i=1; i<=N; i++) {
		int x; scanf("%d", &x);
		nVis[i][i] = true;
		nVis[x][i] = true;
	}
	for(int i=1; i<=N; i++) for(int j=0; j<=M+1; j++) Dy[i][j] = INF;
	for(int i=1; i<=N; i++) Dy[i][1] = 0;

	for(int j=S+1; j<=M+1; j++) {
		for(int i=1; i<=N; i++) while(!minV[i].empty() && minV[i].front().two < j-E) minV[i].pop_front();
		int lx = j-S, ly = j-S;
		if(j == M+1) ly = M;
		for(int ix=lx; ix<=ly; ix++) for(int i=1; i<=N; i++) {
			if(Dy[i][ix] == INF) continue;
			int v = Dy[i][ix] + getSum(i, ix, M+10);
			while(!minV[i].empty() && minV[i].back().one >= v) minV[i].pop_back();
			minV[i].push_back(pi(v, ix));
		}

		vector<pi> list;
		for(int i=1; i<=N; i++) {
			if(minV[i].empty()) continue;
			int v, jj; tie(v, jj) = minV[i].front();
			list.push_back(pi(v-getSum(i, j, M+10)+T, i));
			if((int)list.size() > 3) {
				sort(ALL(list));
				list.pop_back();
			}
		}

		for(int i=1; i<=N; i++) {
			for(pi &e : list) {
				int v, ix; tie(v, ix) = e;
				if(nVis[ix][i]) continue;
				Dy[i][j] = min(Dy[i][j], v);
				break;
			}
		}
	}
	int Ans = INF;
	for(int i=1; i<=N; i++) Ans = min(Ans, Dy[i][M+1] - T);
	printf("%d\n", Ans);
	return 0;
}
