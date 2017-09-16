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

const int MAX_N = 1e6 + 100;

bool notP[MAX_N];
int N;

int Chk[MAX_N]; bool Dy[MAX_N];
int get(int k)
{
	int r = 0;
	while(k) { r += (k%10)*(k%10); k /= 10; }
	return r;
}
bool isHappy(int k)
{
	if(Chk[k] == 1) return Dy[k];
	Chk[k] = 1;
	Dy[k] = isHappy(get(k));
	return Dy[k];
}

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;
	Chk[1] = 1; Dy[1] = true;
	for(int i=2; i<=N; i++)
	{
		if(notP[i] == true) continue;
		for(int j=i*2; j<=N; j+=i) notP[j] = true;
		if(isHappy(i)) printf("%d\n", i);
	}

	return 0;
}