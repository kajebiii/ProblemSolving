
struct BIT {
	int P; vector<int> val;
	BIT(int n) { // 0 to n-1
		P = n + 5;
		val = vector<int>(P, 0);
	}
	void update(int v, int k) { for(v+=2;v<P; v+=v&-v) val[v]+=k; }
	int getSum(int v) { int res=0;for(v+=2;v>0; v-=v&-v) res+=val[v]; return res; }
	int getSum(int a, int b) { return getSum(b) - getSum(a-1); }
};

struct BIT {
	int P; vector<int> val;
	BIT(int n) { // 0 to n-1
		P = n + 5;
		val = vector<int>(P, 0);
	}
	void update(int v, int k) { for(;v<P; v+=v&-v) val[v]+=k; }
	int getSum(int v) { int res=0;for(;v>0; v-=v&-v) res+=val[v]; return res; }
	int getSum(int a, int b) { return getSum(b) - getSum(a-1); }
};

const int MAX_N = 1393232;
struct BITT {
	int val[MAX_N];
	BITT() {}
	void update(int v, int k) {
		while(v < MAX_N) {
			val[v] += k;
			v += v & -v;
		}
	}
	int getCnt(int v) {
		int res = 0;
		while(v > 0) {
			res += val[v];
			v -= v & -v;
		}
		return res;
	}
	int getCnt(int a, int b) {
		return getCnt(b) - getCnt(a-1);
	}
	void clear() {
		for(int i=0; i<MAX_N; i++) val[i] = 0;
	}
};

//dotorya

int bit[150000];
void update(int p, int v) {
	for(; p <= 123123123; p += p &(-p)) bit[p] += v;
}
int getsum(int p) {
	int rv = 0;
	for(; p; p -= p & (-p)) rv += bit[p];
	return rv;
}
