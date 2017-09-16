#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = (250 + 10)*2, MOD = 2e8;

int N, M, C[MAX_N][MAX_N], Chk[MAX_N][MAX_N];
int Dy[MAX_N][MAX_N], P[MAX_N][MAX_N];
int UNF[MAX_N], Cnt[MAX_N];
int F(int v) {return UNF[v]==v?v:UNF[v]=F(UNF[v]); }
void U(int a, int b) {UNF[F(a)] = F(b);}
vector<int> List[MAX_N];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		for(int i=0; i<=2*N; i++) for(int j=0; j<=2*N; j++) C[i][j] = Dy[i][j] = P[i][j] = Chk[i][j] = 0;
		for(int i=1; i<=2*N; i++) UNF[i] = i, Cnt[i] = 0;
		while(M--) {
			int a, b; scanf("%d%d", &a, &b);
			C[a][b] = C[b][a] = 1;
		}
		for(int i=1; i<=2*N; i++) for(int j=i+1; j<=2*N; j++) if(C[i][j] == 0) U(i, j);
		for(int i=1; i<=2*N; i++) Cnt[F(i)]++, List[F(i)].push_back(i);
		vector<int> root; root.push_back(-1);
		for(int i=1; i<=2*N; i++) if(Cnt[i] > 0) root.push_back(i);
		Dy[0][0] = 1; Chk[0][0] =1;
		int rN = root.size();
		for(int p=1; p<rN; p++) {
			int ix = root[p], val = Cnt[ix];
			for(int j=0; j<=2*N; j++)
				if(Chk[p-1][j])
				{
					Dy[p][j+val] += Dy[p-1][j], P[p][j+val] = j, Dy[p][j+val] %= MOD; Chk[p][j+val] = 1;
					Dy[p][j] += Dy[p-1][j], P[p][j] = j, Dy[p][j] %= MOD; Chk[p][j] = 1;
				}
		}
		printf("%d\n", Dy[rN-1][N]/2);
		vector<int> Ans;
		for(int p=rN-1, j=N; p>=1; p--) {
			if(j != P[p][j]) for(int x : List[root[p]]) Ans.push_back(x);
			j = P[p][j];
		}
		sort(Ans.begin(), Ans.end());
		for(int x : Ans) printf("%d ", x); puts("");

		for(int i=1; i<=2*N; i++) {
			vector<int> temp;
			List[i].swap(temp);
		}
	}
	return 0;
}