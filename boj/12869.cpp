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

int V[3], N;
bool Vis[65][65][65]; int Dy[65][65][65];

int getAns(int a, int b, int c) {
	if(Vis[a][b][c]) return Dy[a][b][c]; Vis[a][b][c] = true;
	if(a+b+c == 0) return Dy[a][b][c] = 0;
	int dm[3] = {1, 3, 9};
	int ch[3] = {0, 1, 2};
	int ans = INF;
	do{
		int nr[3] = {a, b, c};
		for(int k=0; k<3; k++) nr[k] = max(0, nr[k] - dm[ch[k]]);
		ans = min(ans, getAns(nr[0], nr[1], nr[2]) + 1);
	}while(next_permutation(ch, ch+3));
	return Dy[a][b][c] = ans;
}
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &V[i]);
	printf("%d\n", getAns(V[0], V[1], V[2]));
	return 0;
}


