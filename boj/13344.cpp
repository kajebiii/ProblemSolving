#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> pi;
const int MAX_N = 5e4 + 100;

int N, M, UNF[MAX_N];
int F(int v) {return UNF[v]==v?v:UNF[v]=F(UNF[v]);}
void U(int a, int b) {UNF[F(a)] = F(b); }
vector<int> Ed[MAX_N]; int inD[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) UNF[i] = i;

	vector<pi> Qs;
	for(int _=0; _<M; _++) {
		int a, b; char t;
		scanf("%d %c %d", &a, &t, &b);
		if(t == '=') U(a, b);
		else Qs.emplace_back(a, b);
	}
	for(auto &p : Qs) {
		int a, b; tie(a, b) = p;
		Ed[F(a)].push_back(F(b));
		inD[F(b)]++;
	}

	queue<int> Q; for(int i=0; i<N; i++) if(inD[i] == 0) Q.push(i);
	int cnt = 0;
	while(!Q.empty()) {
		int v = Q.front(); Q.pop(); cnt++;
		for(int w : Ed[v])
			if(--inD[w] == 0)
				Q.push(w);
	}
	puts(cnt==N?"consistent":"inconsistent");
	return 0;
}