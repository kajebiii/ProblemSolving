#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

const int MAX_N = 1e6 + 100;
typedef long long ll;
const ll LINF = 0x7fffffffffff;

int N, Nr[MAX_N][2];
vector<pair<ll, int>> List;
int findMin(int ix, int d) {
	ll l = (Nr[ix][0] > 0 ? findMin(Nr[ix][0], d+1) : -Nr[ix][0]);
	ll r = (Nr[ix][1] > 0 ? findMin(Nr[ix][1], d+1) : -Nr[ix][1]);
	if(l > 0) List.push_back(make_pair(l, d));
	if(r > 0) List.push_back(make_pair(r, d));
	return -1;
}
bool alessb(pair<ll, int> a, pair<ll, int> b) {
	int minV = min(a.second, b.second);
	a.second -= minV; b.second -= minV;
	while(a.second > 0) {
		if(a.first > LINF) break;
		a.first *= 2;
		a.second--;
	}
	while(b.second > 0) {
		if(b.first > LINF) break;
		b.first *= 2;
		b.second--;
	}
	if(a.second > 0) return false;
	if(b.second > 0) return true;
	return a.first < b.first;
}
int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d%d", &Nr[i][0], &Nr[i][1]);
	findMin(1, 1);

	pair<ll, int> ans = make_pair(0, 0);
	for(pair<ll, int> val : List) {
		if(alessb(ans, val)) ans = val;
	}
	function<void(int)> printBinary = [&](ll n) {
		if(n == 0) return;
		printBinary(n/2);
		printf("%d", n%2);
	};
	printBinary(ans.first);
	for(int i=0; i<ans.second; i++) printf("0");
	return 0;
}