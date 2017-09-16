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

int P, W;
int Cnt[8] = {3, 3, 3, 3, 3, 4, 3, 4};

const int MAX_N = 1e3 + 100;
int N;
char S[MAX_N];
int main() {
	map<char, pi> Mp;
	for(int i=0, now=0; i<8; now+=Cnt[i++])
		for(int k=now; k<now+Cnt[i]; k++)
			Mp[k+'A'] = pi(i+2, k-now+1);
	Mp[' '] = pi(1, 1);
	scanf("%d%d\n", &P, &W);
	
	fgets(S, MAX_N, stdin);
	N = strlen(S);
	int ans = 0;
	for(int i=0; i<N; i++) {
		if(S[i] == '\n') break;
		ans += P * Mp[S[i]].two;
		if(i && Mp[S[i-1]].one == Mp[S[i]].one && Mp[S[i]].one != 1) ans += W;
	}
	printf("%d\n", ans);
	return 0;
}


