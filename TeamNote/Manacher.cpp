const int MAX_N = 4e6 + 100;

int Nr[MAX_N], N, P[MAX_N];
char S[MAX_N];
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
	scanf("%s", S+1);
	N = strlen(S+1);
	for(int i=1; i<=N; i++) Nr[i*2] = S[i] - 'A' + 1;
	N = 2*N + 1;
	getP();
	ll ans = 0;
	for(int i=1; i<=N; i++) ans += (P[i]+1) / 2;
	printf("%lld\n", ans);
	return 0;
}
