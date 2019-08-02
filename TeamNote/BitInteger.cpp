const int MAX_BINT_L = 2e2 + 10;
struct BINT{
	vector<int> nr;
	BINT() {
		nr = vector<int>(MAX_BINT_L, 0);
	}
	BINT operator+(const BINT &o) {
		BINT res = BINT();
		int n = SZ(nr);
		for(int i=0; i<n; i++) {
			res.nr[i] += nr[i] + o.nr[i];
			if(i+1<n) res.nr[i+1] += res.nr[i] / 10;
			res.nr[i] %= 10;
		}
		return res;
	}
	BINT operator-(const BINT &o) { // result must be positive
		BINT res = BINT();
		int n = SZ(nr);
		for(int i=0; i<n; i++) {
			res.nr[i] += nr[i] - o.nr[i];
			while(!(res.nr[i] >= 0 && res.nr[i] < 10)) {
				if(i+1<n) res.nr[i+1] += res.nr[i] / 10;
				res.nr[i] %= 10;
			}
		}
		return res;
	}
	BINT operator*(const BINT &o) {
		BINT res = BINT();
		int n = SZ(nr);
		for(int i=0; i<n; i++) for(int j=0; j<n; j++) 
			if(i+j < n) res.nr[i+j] += nr[i] * o.nr[j];
		for(int i=0; i<n; i++) {
			if(i+1<n) res.nr[i+1] += res.nr[i] / 10;
			res.nr[i] %= 10;
		}
		return res;
	}
	BINT operator/(int d) {
		BINT res = BINT();
		int n = SZ(nr);
		for(int i=n-1, sum=0; i>=0; i--) {
			sum *= 10;
			sum += nr[i];
			res.nr[i] = sum / d;
			sum %= d;
		}
		return res;
	}
	bool operator<(const BINT &o) {
		int n = SZ(nr);
		for(int i=n-1; i>=0; i--) if(nr[i] != o.nr[i]) return nr[i] < o.nr[i];
		return false;
	}
	void print() {
		int n = SZ(nr);
		bool notOne = false;
		for(int i=n-1; i>=0; i--) {
			if(nr[i] != 0) notOne = true;
			if(notOne) printf("%d", nr[i]);
		}
		if(not notOne) puts("0"); else puts("");
	}
};
