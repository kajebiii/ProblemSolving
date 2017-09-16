#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e3 + 100;

int N, M, K;
bool isIn[MAX_N][MAX_N];
struct PP {
	int x, y, v, t; //[t = 0 left, t = 1 right]
	bool annoy, finish; int m;
	PP() {}
	PP(int x_, int y_, int v_, int t_) : x(x_), y(y_), v(v_), t(t_) {}
	bool operator<(const PP &o) const {
		if(t != o.t) return t > o.t; // right -> left
		if(x != o.x) return x < o.x; // top -> down
		if(t == 1) return y > o.y;
		return y < o.y;
	}
};

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d", &M, &N, &K);
		vector<PP> RPs, LPs;
		for(int k=0; k<K; k++) {
			int x, y, v; char S[3]; scanf("%d%d%d%s", &x, &y, &v, S);
			int t = 0;
			if(S[0] == 'R') t = 1;
			if(t == 1)
				RPs.emplace_back(y, x, v, t);
			else
				LPs.emplace_back(y, x, v, t);
			isIn[y][x] = true;
		}
		int outP = 0, ans = 0;
		while(outP < K) {
			ans++;
			for(PP &p : RPs) p.annoy = p.finish = false, p.m = p.v;
			for(PP &p : LPs) p.annoy = p.finish = false, p.m = p.v;
			sort(RPs.begin(), RPs.end());
			sort(LPs.begin(), LPs.end());

			bool moved = false;
			auto letsMove = [&](PP &p, int dy) {
				if(p.finish == true) return;
				if(p.annoy == true) return;
				int before = p.m;
				isIn[p.x][p.y] = false;
				if(isIn[p.x][p.y+dy] == false && p.m >= 1) {
					moved = true;
					p.m--;
					p.y += dy;
				}
				if(p.y == 0 || p.y > M) {
					outP++;
					p.finish = true;
					return;
				}
				isIn[p.x][p.y] = true;

				if(before == p.m)
					if(p.m != 0 && p.v - p.m <= (p.v + 1) / 2)
						p.annoy = true;
			};
			while(1) {
				moved = false;
				for(PP &p : RPs) letsMove(p, +1);
				if(moved == false) break;
			}
			while(1) {
				moved = false;
				for(PP &p : LPs) letsMove(p, -1);
				if(moved == false) break;
			}
//			printf("Move\n"); for(PP &p : RPs) printf("%d %d : finish %d : annoy %d\n", p.x, p.y, p.finish, p.annoy); for(PP &p : LPs) printf("%d %d : finish %d : annoy %d\n", p.x, p.y, p.finish, p.annoy);
			for(auto it = RPs.begin(); it != RPs.end();)
				if(it->finish == true) it = RPs.erase(it); else it++;
			for(auto it = LPs.begin(); it != LPs.end();)
				if(it->finish == true) it = LPs.erase(it); else it++;

			auto letsGo = [&](PP &p, int d) {
				if(p.x+d <= 0 || p.x+d > N) return;
				if(isIn[p.x+d][p.y] == false) {
					isIn[p.x][p.y] = false;
					isIn[p.x+d][p.y] = true;
					p.annoy = false;
					p.x = p.x + d;
				}
			};
			for(PP &p : RPs) if(p.annoy == true) letsGo(p, -1);
			reverse(LPs.begin(), LPs.end());
			for(PP &p : LPs) if(p.annoy == true) letsGo(p, +1);
			reverse(RPs.begin(), RPs.end());
			for(PP &p : RPs) if(p.annoy == true) letsGo(p, +1);
			reverse(LPs.begin(), LPs.end());
			for(PP &p : LPs) if(p.annoy == true) letsGo(p, -1);

//			printf("Annoy\n"); for(PP &p : RPs) printf("%d %d : finish %d : annoy %d\n", p.x, p.y, p.finish, p.annoy); for(PP &p : LPs) printf("%d %d : finish %d : annoy %d\n", p.x, p.y, p.finish, p.annoy);
		}
		printf("%d\n", ans);
	}
	return 0;
}