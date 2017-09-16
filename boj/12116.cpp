#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll S, A, N;
vector<pair<ll, ll>> Ans;
void Uplus(ll A, ll B) {
	if(A > B) swap(A, B);
	B -= A - 1;
	B /= 2;
	if(A == 1) return;
	Ans.push_back(make_pair(B, B+A-1));
}

int main() {
	scanf("%lld", &S);
	S *= 2;
	ll pow = 1;
	while(S % 2 == 0) pow *= 2, S /= 2;

	for(ll i=1; i*i<=S; i++) {
		if(S % i != 0) continue;
		Uplus(S/i, i * pow);
		Uplus(S/i * pow, i);
	}
	sort(Ans.begin(), Ans.end());
	Ans.erase(unique(Ans.begin(), Ans.end()), Ans.end());
	for(auto ans : Ans) printf("%lld %lld\n", ans.first, ans.second);
	return 0;
}