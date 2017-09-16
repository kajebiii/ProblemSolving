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

const int MAX_N = 1e5 + 100;

char S[MAX_N];
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; cin >> TC;
	while(TC--)
	{
		deque<int> Q;
		scanf("\n%s", S);
		int N; scanf("%d\n[", &N); 
		for(int i=0, x; i<N; i++) scanf("%d,", &x), Q.push_back(x);
		scanf("]");

		int cnt = 0;
		for(int i=0; S[i] != 0; i++)
			if(S[i] == 'D') cnt++;
		if(cnt > N) { puts("error"); continue; }
		bool front = true;
		for(int i=0; S[i] != 0; i++)
		{
			if(S[i] == 'R') front = !front;
			else if(front) Q.pop_front();
			else Q.pop_back();
		}
		if(front == false) reverse(Q.begin(), Q.end());
		if(Q.size() == 0) { puts("[]"); continue; }
		printf("[%d", Q.front()); Q.pop_front();
		while(!Q.empty()) printf(",%d", Q.front()), Q.pop_front();
		printf("]\n");
	}

	return 0;
}