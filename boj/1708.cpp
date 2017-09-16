#include <stdio.h>
#include <algorithm>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pi;

const int INF = 0x7fffffff, MAX_N = 1e5 + 100;

int N; pi P[MAX_N];
int ccw(int a, int b, int c)
{
	int bx = P[b].fi - P[a].fi, by = P[b].se - P[a].se;
	int cx = P[c].fi - P[a].fi, cy = P[c].se - P[a].se;
	long long val = 1ll * bx * cy - 1ll * by * cx;
	if(val > 0) return 1;
	else if(val == 0) return 0;
	return -1;
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d%d", &P[i].fi, &P[i].se);
	sort(P, P+N);
	int ans = 0;
	vector<int> Idx;
	for(int i=0; i<N; i++) {while(Idx.size() >= 2 && ccw(Idx[Idx.size()-2], Idx.back(), i) != -1) Idx.pop_back(); Idx.push_back(i);}
	ans += Idx.size();
	while(Idx.size() > 0) Idx.pop_back();
	for(int i=0; i<N; i++) {while(Idx.size() >= 2 && ccw(Idx[Idx.size()-2], Idx.back(), i) != +1) Idx.pop_back(); Idx.push_back(i);}
	ans += Idx.size();
	printf("%d", ans-2);
	return 0;
}










