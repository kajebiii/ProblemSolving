#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
const int MAX_N = 1e2 + 10;

int N, M, P, L;
int toNr(int x, int y) {return x*M+y;}
pi toPi(int v) {return make_pair(v/M, v%M);}
int UNF[MAX_N*MAX_N], Have[MAX_N*MAX_N];
int F(int v) {return UNF[v]==v?v:UNF[v]=F(UNF[v]); }
void U(int a, int b) {UNF[F(a)] = F(b); }
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d", &N, &M, &P, &L);
		for(int i=0; i<N*M; i++) UNF[i] = i, Have[i] = 0;
		vector<int> pow;
		for(int i=0; i<P; i++) {
			int x, y; scanf("%d%d", &x, &y);
			pow.push_back(toNr(x, y));
		}
		for(int i=0; i<L; i++) {
			int x, y; char c[9]; scanf("%d%d%s", &x, &y, c);
			int k = ((c[0]=='U')?0:1);
			int nx = x + "12"[k] - '1', ny = y + "21"[k] - '1';
			U(toNr(x, y), toNr(nx, ny));
		}
		for(int x : pow) Have[F(x)] = 1;
		int ans = 0;
		for(int i=0; i<N*M; i++) if(F(i) == i && Have[i] == 0) ans++;
		printf("%d\n", ans);
	}
	return 0;
}