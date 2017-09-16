#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)((v).size()))
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 5e3 + 100;

int N; char S[MAX_N]; int Dy[MAX_N][MAX_N];
int main() {
	cin >> N;
	scanf("%s", S+1);
	for(int i=1; i<=N; i++) for(int j=i; j<=N; j++) Dy[i][j] = INF;
	for(int p=1; p<=N; p++) for(int i=1, j=p; j<=N; i++, j++) {
		if(S[i] == S[j]) Dy[i][j] = min(Dy[i][j], Dy[i+1][j-1]);
		Dy[i][j] = min(Dy[i][j], Dy[i+1][j] + 1);
		Dy[i][j] = min(Dy[i][j], Dy[i][j-1] + 1);
		//printf("%d %d -> %d\n", i, j, Dy[i][j]);
	}
	printf("%d\n", Dy[1][N]);
	return 0;
}


