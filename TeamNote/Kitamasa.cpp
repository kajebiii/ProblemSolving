const int MAX_N = 1e3 + 10;

const int MOD = 1999;

void kitamasa(ll n, int &m, vector<int> &c, vector<int> &d) {
	if(n <= m) {
		for(int i=1; i<=m; i++) d[i] = 0;
		d[n] = 1;
		return;
	}
	if(n%2 == 1) {
		kitamasa(n-1, m, c, d);
		int dm = d[m];
		for(int i=m; i>=1; i--) d[i] = (d[i-1] + 1ll*c[m+1-i]*dm) % MOD;
	}else{
		kitamasa(n/2, m, c, d);
		vector<int> t(2*m+1, 0);
		for(int i=1; i<=m; i++) for(int j=1; j<=m; j++)
			t[i+j] = (t[i+j] + 1ll * d[i] * d[j]) % MOD;
		for(int i=m+m; i>m; i--) for(int j=1; j<=m; j++)
			t[i-j] = (t[i-j] + 1ll * c[j] * t[i]) % MOD;
		for(int i=1; i<=m; i++) d[i] = t[i];
	}
}

const int MAX_M = 1e3 + 100;

int A[MAX_M];
int N, M;
int main() {
	scanf("%d%d", &N, &M);
	vector<int> C, D;
	C = D = vector<int>(M+1);
	for(int i=1; i<=M; i++) scanf("%d", &A[i]);
	for(int i=1; i<=M; i++) scanf("%d", &C[i]);

	kitamasa(N, M, C, D);
	int ans = 0;
	for(int i=1; i<=N; i++) ans = (ans + 1ll * A[i] * D[i]) % MOD;
	printf("%d\n", ans);
	return 0;
}
