#include <stdio.h>
#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int MAX_N = 1e4 + 100;

bool notP[MAX_N];
int N;

vector<int> Multi(vector<int> A, vector<int> B)
{
	vector<int> R = vector<int>(A.size() + B.size() + 1, 0);
	for(int i=0; i<A.size(); i++) for(int j=0; j<B.size(); j++)
		R[i+j] += A[i] * B[j];
	for(int i=0; i<R.size() - 1; i++)
		R[i+1] += R[i] / 10, R[i] %= 10;
	return R;
}

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;

	vector<int> ans = vector<int>(1, 1);
	notP[1] = true;
	for(int i=2; i<=N; i++)
	{
		if(notP[i] == true) continue;
		for(int j=i*2; j<=N; j+=i) notP[j] = true;
		int cnt = 0;
		int temp = N;
		while(temp) cnt += temp / i, temp /= i;
		cnt *= 2; cnt += 1;
		vector<int> now;
		while(cnt) now.pb(cnt%10), cnt /= 10;
		ans = Multi(ans, now);
	}

	bool flag = false;
	for(int i=ans.size()-1; i>=0; i--)
	{
		if(ans[i] != 0) flag = true;
		if(flag) printf("%d", ans[i]);
	}
	return 0;
}