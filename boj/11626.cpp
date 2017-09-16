#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;

struct IDX {
	int P; vector<int> val;
	IDX(int n) {
		for(P=1; P<n; P<<=1);
		val = vector<int>(2*P, 0);
	}
	void update(int v, int k) {
		val[v+=P] = k;
		while(v/=2) val[v] = max(val[v*2], val[v*2+1]);
	}
	int getMax(int a, int b) {
		a+=P;b+=P;
		int res = 0;
		while(a<=b) {
			if(a%2 == 1) res = max(res, val[a++]);
			if(b%2 == 0) res = max(res, val[b--]);
			a/=2;b/=2;
		}
		return res;
	}
};

int N, Nr[MAX_N];
int main() {
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]), Nr[i]--;
		IDX idx = IDX(N);
		vector<int> list;
		for(int i=N-1; i>=0; i--) {
			int maxV = idx.getMax(0, Nr[i]);
			if(maxV == 1) list.push_back(Nr[i]+1);
			idx.update(Nr[i], 1);
		}
		sort(list.begin(), list.end());
		printf("%d\n", (int)list.size());
		for(int x : list) printf("%d\n", x);
	}
	return 0;
}