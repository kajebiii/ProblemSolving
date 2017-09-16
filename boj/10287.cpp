#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 1e4 + 100;
typedef long long ll;

int N, M;
ll Nr[MAX_N], GNr[MAX_N], P;
vector<int> Ed[MAX_N];
vector<int> Glist[MAX_N];

int Ix[MAX_N], IN, Gp[MAX_N], GN; stack<int> S;
int getLow(int v) {
	int low;
	low = Ix[v] = ++IN; S.push(v);
	for(int w : Ed[v]) {
		if(Ix[w] == 0) low = min(low, getLow(w));
		else if(Gp[w] == 0) low = min(low, Ix[w]);
	}
	if(low == Ix[v])
		for(GN++; ;) {
			int now = S.top(); S.pop();
			Gp[now] = GN;
			if(now == v) break;
		}
	return low;
}
ll ggcd(ll a, ll b) {return b==0?a:ggcd(b, a%b);}

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%lld", &N, &M, &P);
		while(M--) {
			int x, y; scanf("%d%d", &x, &y);
			Ed[x].push_back(y);
		}
		for(int i=1; i<=N; i++) scanf("%lld", &Nr[i]);

		for(int i=1; i<=N; i++) 
			if(Ix[i] == 0) getLow(i);
		for(int i=1; i<=GN; i++) GNr[i] = 0;
		for(int i=1; i<=N; i++) {
			GNr[Gp[i]] = ggcd(GNr[Gp[i]], Nr[i]);
			Glist[Gp[i]].push_back(i);
		}
		for(int g=GN; g>=1; g--) {
			for(int v : Glist[g])
				for(int w : Ed[v])
					GNr[Gp[w]] = ggcd(GNr[Gp[w]], GNr[g]);
		}
		int ans = 0;
		for(int i=1; i<=N; i++)
			if(GNr[Gp[i]] == P) ans++;
		printf("%d\n", ans);


		for(int i=1; i<=N; i++) {
			vector<int> temp[2];
			Ed[i].swap(temp[0]);
			if(i <= GN)
				Glist[i].swap(temp[1]);
		}
		for(int i=1; i<=N; i++) Ix[i] = 0, Gp[i] = 0;
		IN = GN = 0;
	}
	return 0;
}