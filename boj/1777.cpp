#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;

struct IDX {
	int P; vector<int> val;
	IDX(int n) {
		for(P=1; P<n; P<<=1);
		val = vector<int>(P*2, 0);
	}
	void update(int v, int k) {
		val[v+=P] = k;
		while(v/=2) val[v] = val[v*2] + val[v*2+1];
	}
	int findKth(int v, int k) {
		if(v >= P) return v - P;
		if(val[v*2] >= k) return findKth(v*2, k);
		return findKth(v*2+1, k - val[v*2]);
	}
};

int N, Nr[MAX_N], Ans[MAX_N];

int main() {
	scanf("%d", &N); for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	IDX idx = IDX(N);
	for(int i=0; i<N; i++) idx.update(i, 1);
	for(int i=N-1; i>=0; i--) {
		int ix = idx.findKth(1, i+1-Nr[i]);
		Ans[ix] = i+1;
		idx.update(ix, 0);
	}
	for(int i=0; i<N; i++) printf("%d ", Ans[i]);
	return 0;
}