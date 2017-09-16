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

const int MAX_N = 1e2 + 10;

int N, Nr[MAX_N], State[MAX_N]; char Mp[MAX_N];
int main() {
	int TC; cin >> TC;
	while(TC--) {
		scanf("%d", &N);
		for(int i=1; i<=N; i++) scanf("%1d", &Nr[i]);
		scanf("%s", Mp+1);
		int ans = 0;
		for(int s=0; s<2; s++) {
			bool isCan = true;
			State[1] = s;
			for(int i=2; i<=N+1; i++) State[i] = Nr[i-1] - State[i-1] - State[i-2];
			int sum = 0;
			for(int i=1; i<=N+1; i++) {
				sum += State[i];
				if(i <= N && Mp[i] == '*' && State[i] != 1) isCan = false;
				if(State[i] < 0 || State[i] > 1) isCan = false;
				if(i == N+1 && State[i] != 0) isCan = false;
			}
			if(isCan) ans = max(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}


