struct MAT{
	vector<vector<int>> nr;
	MAT(int n, bool isZero = false) {
		nr = vector<vector<int>>(n, vector<int>(n, 0));
		if(not isZero) for(int i=0; i<n; i++) nr[i][i] = 1;
	}
	MAT operator*(const MAT &o) {
		int n = SZ(nr);
		MAT res = MAT(n, true);
		for(int k=0; k<n; k++) for(int i=0; i<n; i++) for(int j=0; j<n; j++) 
			res.nr[i][j] = (res.nr[i][j] + 1ll * nr[i][k] * o.nr[k][j]) % MOD;
		return res;
	}
	void print() {
		int n = SZ(nr);
		for(int i=0; i<n; i++, puts("")) for(int j=0; j<n; j++) printf("%d ", nr[i][j]);
	}
};
