struct IDX {
	int P; vector<int> val;
	IDX(int N) {
		for(P=1; P<N; P<<=1);
		val = vector<int>(P*2, 0);
	}
	void update(int v, int k) {
		val[v+=P] = k;
		while(v>>=1) val[v] = val[v*2] + val[v*2+1];
	}
	int getSum(int a, int b) {
		int res = 0;
		for(a+=P, b+=P; a<=b; a>>=1, b>>=1) {
			if(a%2==1) res += val[a++];
			if(b%2==0) res += val[b--];
		}
		return res;
	}
};
