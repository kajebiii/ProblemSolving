int mymul(int a, int b, int mod) {
	return 1ll * a * b % mod;
	ll res = 0, p = a;
	while(b) {
		if(b%2) res+=p, res%=mod;
		p+=p; p%=mod;
		b>>=1;
	}
	return res;
}
int mypow(int a, int b, int mod) {
	ll res = 1, p = a;
	while(b) {
		if(b%2) res = mymul(res, p, mod);
		p = mymul(p, p, mod);
		b>>=1;
	}
	return res;
}
int Fac[MAX_N];
void initFac(int n, int mod) {
	Fac[0] = Fac[1] = 1; for(int i=2; i<=n; i++) Fac[i] = 1ll * Fac[i-1] * i % mod;
}
ll nCk(int n, int k, int mod) {
	if(k > n) return 0ll;
	return 1ll * Fac[n] * mypow(1ll * Fac[n-k] * Fac[k] % mod, mod-2, mod) % mod;
}
