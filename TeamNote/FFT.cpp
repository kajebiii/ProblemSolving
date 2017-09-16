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


//XOR convolution
void FWHT(vector<int> &a, bool invert) {
	int n = SZ(a);
	for(int len=2; len<=n; len<<=1) {
		for(int i=0; i<n; i+=len) {
			for(int j=0; j<len/2; j++) {
				int u = a[i+j], v = a[i+j+len/2];
				a[i+j] = u+v;
				a[i+j+len/2] = u-v;
			}
		}
	}
//	if(invert) for(int i=0; i<n; i++) a[i] /= n;
	if(invert) for(int i=0; i<n; i++) a[i] = 1ll * a[i] * mul(n, MOD-2) % MOD;
}

int N; vector<int> A, B, C;
typedef complex<double> base;
const double PI = atan(1) * 4;

void FFT(vector<base> &a, bool invert) {
	int n = SZ(a);
	for(int i=1, j=0, bit; i<n; i++) {
		for(bit=n>>1; j>=bit; bit>>=1) j -= bit; j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	for(int len=2; len<=n; len<<=1) {
		double theta = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(theta), sin(theta));
		for(int i=0; i<n; i+=len) {
			base w(1, 0);
			for(int j=0; j<len/2; j++) {
				int ai = i+j, bi = i+j+len/2;
				base u = a[ai], v = a[bi] * w;
				a[ai] = u + v;
				a[bi] = u - v;
				w *= wlen;
			}
		}
	}
	if(invert) for(int i=0; i<n; i++) a[i] /= n;
}

void multi(const vector<int> &a, const vector<int> &b, vector<int> &res) {
	int n = SZ(a);
	vector<base> fa(ALL(a)), fb(ALL(b));
	FFT(fa, false); FFT(fb, false);
	for(int i=0; i<n; i++) fa[i] *= fb[i];
	FFT(fa, true);
	for(int i=0; i<n; i++) res[i] = (fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

int main() {
	cin >> N;
	int n; for(n=1; n<N; n<<=1); n <<= 1;
	A = B = C = vector<int>(n, 0);
	for(int i=0; i<N; i++) scanf("%d", &A[i]);
	for(int i=0; i<N; i++) scanf("%d", &B[i]);
	reverse(B.begin(), B.begin() + N);

	multi(A, B, C);

	int ans = -INF;
	for(int i=0; i<N; i++) ans = max(ans, C[i] + C[i+N]);
	printf("%d\n", ans);

	return 0;
}