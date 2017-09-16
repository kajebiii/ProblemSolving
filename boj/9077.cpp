#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_L = 1e4;

int N; vector<int> List[MAX_L+1];
struct IDX {
	int P; vector<int> val;
	IDX(int n) {
		for(P=1; P<n; P<<=1);
		val = vector<int>(2*P, 0);
	}
	void update(int v, int k) {
		val[v+=P] += k;
		while(v/=2) val[v] = max(val[v*2], val[v*2+1]);
	}
	int getMax(int a, int b) {
		int res = 0;
		a += P, b += P;
		while(a<=b) {
			if(a%2==1) res = max(res, val[a++]);
			if(b%2==0) res = max(res, val[b--]);
			a/=2;b/=2;
		}
		return res;
	}
};
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			int x, y; scanf("%d%d", &x, &y);
			List[x].push_back(y);
		}
		IDX idx = IDX(MAX_L+1);
		int ans = 0;
		for(int r=0; r<=MAX_L; r++) {
			if(r >= 11)
				for(int y : List[r-11]) for(int j=10; j>=0; j--)
					if(y >= j) idx.update(y-j, -1);
			for(int y : List[r]) for(int j=10; j>=0; j--)
				if(y >= j) idx.update(y-j, 1);
			ans = max(ans, idx.getMax(0, MAX_L));
		}
		printf("%d\n", ans);

		for(int i=0; i<=MAX_L; i++) {
			vector<int> temp;
			List[i].swap(temp);
		}
	}
	return 0;
}