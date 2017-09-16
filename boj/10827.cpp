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

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

int Point;
vector<int> Ans;
vector<int> Nr;
vector<int> Multi(vector<int> A, vector<int> B)
{
	vector<int> result = vector<int>(A.size() + B.size(), 0);
	for(int i=0; i<A.size(); i++) for(int j=0; j<B.size(); j++)
		result[i+j] += A[i] * B[j];
	for(int i=0; i<result.size(); i++)
		if(result[i] >= 10)
			result[i+1] += result[i] / 10,
			result[i] %= 10;
	return result;
}

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	string S; cin >> S;
	int ix = S.find('.', 0);
	if(ix != -1)
	{
		Point = S.size() - ix - 1;
		S.erase(S.begin() + ix);
	}
	else Point = 0;

	for(int i=S.size()-1; i>=0; i--)
		Nr.pb(S[i] - '0');
	Ans.pb(1);

	int N; cin >> N;
	for(int i=0; i<N; i++)
		Ans = Multi(Ans, Nr);

	bool flag = false; ix = -1;
	for(int i=Ans.size()-1; i>=0; i--)
	{
		if(Ans[i] != 0) {
			flag = true;
			ix = i;
		}
		if(i == Point * N)
			flag = true;
		if(flag)
			printf("%d", Ans[i]);
		if(i == Point * N)
			if(i != 0)
				printf(".");
	}
	return 0;
}