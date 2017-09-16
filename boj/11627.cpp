#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_N = 1e3 + 10;

struct PT {
	int x, y;
	PT() {} PT(int x_, int y_) : x(x_), y(y_) {}
	PT operator+(const PT &o) const { return PT(x+o.x, y+o.y); }
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y); }
	bool operator==(const PT &o) const { return x == o.x && y == o.y;}
};

int N, M; 
PT UNF[2][MAX_N][MAX_N]; bool Me[2][MAX_N][MAX_N];
PT F(int k, int x, int y) {return PT(x, y) ==  UNF[k][x][y] ? PT(x, y) : UNF[k][x][y] = F(k, UNF[k][x][y].x, UNF[k][x][y].y);}
void U(int k, PT n, PT m) {
	n = UNF[k][n.x][n.y]; m = UNF[k][m.x][m.y];
	int a = n.x, b = n.y, x = m.x, y = m.y;
	UNF[k][x][y] = UNF[k][a][b]; Me[k][a][b] |= Me[k][x][y];
}
bool Vis[MAX_N][MAX_N], Adj[MAX_N][MAX_N], R[MAX_N][MAX_N], GVis[MAX_N][MAX_N];
char Mp[MAX_N][MAX_N];
int main() {
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d%d", &M, &N);
		for(int i=0; i<N; i++) scanf("%s", Mp[i]);
		auto inBound = [&](const PT &w) {return w.x >= 0 && w.x < N && w.y >= 0 && w.y < M;};
		PT Gp;
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
			if(Mp[i][j] == 'G') Gp = PT(i, j), GVis[i][j] = true;
			else if(Mp[i][j] == 'R') R[i][j] = true;
		}
		for(int k=0; k<2; k++) for(int i=0; i<N; i++) for(int j=0; j<M; j++) 
			UNF[k][i][j] = PT(i, j);
		for(int l=0; l<2; l++) for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
			if(Mp[i][j] == 'R') continue;
			for(int k=l; k<4; k+=2) {
				PT w = PT(i, j) + PT("0121"[k]-'1', "1210"[k]-'1');
				if(inBound(w) == false) continue;
				if(Mp[w.x][w.y] == 'R') continue;
				U(l, PT(i, j), w);
			}
		}

		queue<pair<PT, int> > Q;
		auto pushM = [&](int x, int y, int t) {
			if(Vis[x][y] == true) return;
			if(Adj[x][y] == false || R[x][y] == true) return;
			Vis[x][y] = true;
			PT vf = F(0, x, y), hf = F(1, x, y);
			Me[0][vf.x][vf.y] = Me[1][hf.x][hf.y] = true;
			for(int k=0; k<4; k++) {
				PT w = PT(x, y) + PT("0121"[k]-'1', "1210"[k]-'1');
				if(inBound(w) == false) continue;
				Adj[w.x][w.y] = true;
				Q.push(make_pair(w, t+1));
			}
		};
		for(int i=0; i<N; i++) for(int j=0; j<M; j++)
			if(Mp[i][j] == 'M') {
				Adj[i][j] = true;
				pushM(i, j, 0);
			}

		int turn = 0, ruined = 0;
		while(1) {
			turn++;
//			printf("%d started\n", turn);
			//
			bool Gmoved = false;
			for(int k=0; k<4; k++) {
				PT w = Gp + PT("0121"[k]-'1', "1210"[k]-'1');
				if(inBound(w) == false) continue;
				if(GVis[w.x][w.y] == true) continue;
				if(R[w.x][w.y] == true) {
					Gmoved = true; Gp = w; GVis[w.x][w.y] = true;
					R[w.x][w.y] = false; ruined++;
					for(int l=0; l<2; l++) for(int k=l; k<4; k+=2) {
						PT n = PT(w.x, w.y) + PT("0121"[k]-'1', "1210"[k]-'1');
						if(inBound(n) == false) continue;
						if(R[n.x][n.y]) continue;
						U(l, w, n);
					}
					Q.push(make_pair(w, turn));
					break;
				}
			}
			if(Gmoved == false) for(int k=0; k<4; k++) {
				PT w = Gp + PT("0121"[k]-'1', "1210"[k]-'1');
				if(inBound(w) == false) continue;
				if(GVis[w.x][w.y] == true) continue;
				Gmoved = true; Gp = w; GVis[w.x][w.y] = true;
				break;
			}

			while(!Q.empty()) {
				PT v; int t; tie(v, t) = Q.front(); if(t > turn) break; Q.pop();
				pushM(v.x, v.y, t);
			}

			PT vf = F(0, Gp.x, Gp.y), hf = F(1, Gp.x, Gp.y);
			if(Me[0][vf.x][vf.y] || Me[1][hf.x][hf.y]) break;
		}
		printf("%d\n", ruined);

		for(int i=0; i<N; i++) for(int j=0; j<M; j++)
			GVis[i][j] = Vis[i][j] = Adj[i][j] = R[i][j] = Me[0][i][j] = Me[1][i][j] = false;
	}
	return 0;
}