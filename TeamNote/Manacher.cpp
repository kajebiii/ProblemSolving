#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REPO(i,n) for(int (i)=1; (i)<=(int)(n); (i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 100;
int Nr[MAX_N], N, P[MAX_N];
void getP() {
	int r = 0, p = 0;
	Nr[0] = -1;
	Nr[N+1] = -2;
	for(int i=1; i<=N; i++) {
		P[i] = (i <= r)?min(P[p - (i-p)], r-i):0;
		while(Nr[i-P[i]-1] == Nr[i+P[i]+1]) P[i]++;
		if(r < i+P[i]) r = i+P[i], p = i;
	}
}


int main() {
	cin >> N; for(int i=1; i<=N; i++) scanf("%d", &Nr[i*2-1]);
	N = 2*N - 1;
	getP();
	return 0;
}