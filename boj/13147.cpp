#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;

const int MAX_N = 1e4 + 100;

map<string, int> Mp;
vector<int> Ed[MAX_N];

int M, N, inD[MAX_N];

int main() {
	scanf("%d", &M);
	rep(i, M) {
		char val[2][33], type[3];
		scanf("%s%s%s", val[0], type, val[1]);
		int k = ((type[0] == '<') ? 0 : 1);
		for(int j=0; j<2; j++) if(Mp.count(val[j]) == 0) Mp[val[j]] = N++;
		int a = Mp[val[k]], b = Mp[val[1-k]];
		Ed[a].push_back(b);
		inD[b]++;
	}

	queue<int> Q;
	rep(i, N) if(inD[i] == 0) Q.push(i);

	int cnt = 0;
	while(!Q.empty()) {
		int v = Q.front(); Q.pop(); cnt++;
		for(int w : Ed[v]) if(--inD[w] == 0) Q.push(w);
	}
	if(cnt != N) printf("im"); puts("possible");
	return 0;
}