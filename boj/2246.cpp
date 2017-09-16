
#include <stdio.h>
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
#define ft first
#define sd second
#define mp make_pair
#ifndef ONLINE_JUDGE
const bool debug = true;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.ft+y.ft, x.sd+y.sd); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

int N; pi Nr[11111];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d%d", &Nr[i].ft, &Nr[i].sd);
	sort(Nr, Nr+N);
	vector<pi> V; V.push_back(make_pair(0, INF));
	for(int i=0; i<N; i++)
	{
		if(V.back().sd <= Nr[i].sd) continue;
		V.push_back(Nr[i]);
	}
	cout << V.size() - 1;
	return 0;
}