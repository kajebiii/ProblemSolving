#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_N = 1e3 + 10;
typedef pair< pair<int, int>, int> pii;

int UNF[MAX_N], N, Nr[MAX_N][2];
int F(int v) {return UNF[v]==v?v:UNF[v]=F(UNF[v]);}
bool U(int a, int b) {a=F(a), b=F(b); UNF[a] = b; return a != b;}

const int fre = 0;
int main() {
	if(fre) freopen("moocast.in", "r", stdin);
	if(fre) freopen("moocast.out", "w", stdout);

	scanf("%d", &N);
	for(int i=0; i<N; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[i][j]);
	auto getDis = [&](int a, int b) { // a -> b
		int dx = Nr[a][0] - Nr[b][0], dy = Nr[a][1] - Nr[b][1];
		return dx * dx + dy * dy;
	};
	vector<pii> Ed;
	for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) Ed.push_back(make_pair(make_pair(i, j), getDis(i, j)));
	sort(Ed.begin(), Ed.end(), [&](const pii &a, const pii &b) {return a.second < b.second;});

	int ans = 0;
	for(int i=0; i<N; i++) UNF[i] = i;
	for(pii &e : Ed) {
		pair<int, int> temp;
		int a, b, c; tie(temp, c) = e; tie(a, b) = temp;
		if(U(a, b)) ans = max(ans, c);
	}
	printf("%d\n", ans);
	return 0;
}