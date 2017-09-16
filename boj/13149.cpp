#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;

const int MAX_N = 22, MAX_NR = 1e3 + 10, INF = 0x3f2f1f0f;

int N; ll K;
vector<int> Nr;
bool Calc[MAX_NR * MAX_NR];
int main() {
	scanf("%d%lld", &N, &K);
	for(int i=0, x; i<N; i++) scanf("%d", &x), Nr.push_back(x);
	sort(Nr.begin(), Nr.end()); Nr.erase(unique(Nr.begin(), Nr.end()), Nr.end()); 
	N = Nr.size();

	int B = Nr.back();
	if(K > B * B) {
		queue<pi> Q; Q.push(make_pair(0, 0)); Calc[0] = true;
		while(!Q.empty()) {
			int v, c; tie(v, c) = Q.front(); Q.pop();
			if(c >= B) break;
			for(int i=0; i<N-1; i++) {
				int w = v + Nr[i]; w %= B;
				if(Calc[w] == true) continue;
				Calc[w] = true;
				Q.push(make_pair(w, c+1));
			}
		}
		if(Calc[K%B] == false) printf("im"); puts("possible");
	} else {
		Calc[0] = true;
		for(int k=0; k<N; k++) for(int i=0; i<B*B; i++) 
			if(Calc[i] == true) Calc[i + Nr[k]] = true;
		if(Calc[K] == false) printf("im"); puts("possible");
	}
	return 0;
}