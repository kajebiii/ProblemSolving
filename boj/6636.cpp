#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
typedef pair<int, int> pi;

const int MAX_L = 1e3 + 10, MAX_N = 1e3 + 10;
int N, L, B, F;
vector<pi> List; vector<int> Sl, Ll;
vector<int> Dy[MAX_L][MAX_N];
void fastC(vector<int> &a, vector<int> &p) {
	int rest = (int)p.size() - (int)a.size();
	for(int i=0; i<rest; i++) a.push_back(0);
	for(int i=0; i<p.size(); i++) a[i] += p[i];
	for(int i=0; i+1<a.size(); i++) {
		a[i+1] += a[i] / 10;
		a[i] %= 10;
	}
	if(a.back() >= 10)
	{
		a.push_back(0);
		a.back() += a[a.size() - 2] / 10;
		a[a.size() - 2] %= 10;
	}
}
vector<int> operator+(vector<int> &a, vector<int> &p) {
	vector<int> res = vector<int>(max(a.size(), p.size()), 0);
	for(int i=0; i<a.size(); i++) res[i] += a[i];
	for(int i=0; i<p.size(); i++) res[i] += p[i];
	for(int i=0; i+1<res.size(); i++) {
		res[i+1] += res[i] / 10;
		res[i] %= 10;
	}
	if(res.back() >= 10) 
	{
		res.push_back(0);
		res.back() += res[res.size() - 2] / 10;
		res[res.size() - 2] %= 10;
	}
	return res;
}
int main() {
	while(scanf("%d%d%d%d", &N, &L, &B, &F) == 4) {
		if(N + L + B + F == 0) break;
		List.clear(); Sl.clear(); Ll.clear();
		for(int i=1; i<=N; i++) {
			int k;
			scanf("%*d%d", &k);
			for(int j=0, x; j<k; j++) 
				scanf("%d", &x), List.push_back(make_pair(i, x));
		}
		for(int i=1, x; i<=B; i++) scanf("%d", &x), List.push_back(make_pair(0, x));
		for(int i=1, x; i<=F; i++) scanf("%d", &x), List.push_back(make_pair(x, N+1));
		if(L > N) {puts("impossible"); continue;}
		for(int i=0; i<=N+1; i++) Dy[1][i] = vector<int>({0});
		Dy[1][0] = vector<int>({1});

		for(int i=2; i<=L+2; i++) {
			for(int j=0; j<=N+1; j++) Dy[i][j] = vector<int>({0});
			for(pi &e : List) {
//				Dy[i][e.second] = Dy[i][e.second] + Dy[i-1][e.first];
				fastC(Dy[i][e.second], Dy[i-1][e.first]);
			}
		}
		if(Dy[L+2][N+1].size() == 1 && Dy[L+2][N+1][0] == 0) {
			puts("impossible"); continue;
		}
		reverse(Dy[L+2][N+1].begin(), Dy[L+2][N+1].end());
		for(int x : Dy[L+2][N+1]) printf("%d", x); puts("");
	}
	return 0;
}