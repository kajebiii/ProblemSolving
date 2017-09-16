#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REPO(i,n) for(int (i)=1; (i)<=(int)(n); (i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 100;

struct IDX {
	int P; vector<int> Val;
	IDX(int N) {
		for(P=1; P<N; P<<=1);
		Val = vector<int>(P*2, 0);
	}
	void update(int v, int k) {
		Val[v += P] = k;
		while(v/=2) Val[v] = max(Val[v*2], Val[v*2+1]);
	}
	int getMax(int a, int b) {
		int result = 0;
		while(a <= b) {
			if(a%2 == 1) result = max(result, Val[a++]);
			if(b%2 == 0) result = max(result, Val[b--]);
			a>>=1;b>>=1;
		}
		return result;
	}
};

int main()
{
	return 0;
}



int mySum(int a, int b) { return a+b; }
int myMax(int a, int b) { return max(a, b); }
struct IDX {
	int P; vector<int> val;
	int initV;
	function<int(int, int)> f;
	IDX(int n, function<int(int, int)> ff) {
		for(P=1; P<n; P<<=1);
		val = vector<int>(2*P);
		f = ff;
	}
	void init(int v) {
		initV = v;
		val = vector<int>(2*P, v);
	}
	void update(int v, int k) {
		v += P;
		val[v] = f(val[v], k);
		while(v/=2) val[v] = f(val[v*2], val[v*2+1]);
	}
	int getF(int a, int b) {
		a += P; b += P;
		int res = initV;
		while(a<=b) {
			if(a%2==1) res = f(res, val[a++]);
			if(b%2==0) res = f(res, val[b--]);
			a>>=1;b>>=1;
		}
		return res;
	}
};