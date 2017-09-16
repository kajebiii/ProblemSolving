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

int N = 6;
int A[6][3];

bool getCan(int v)
{
	if(v == 6) return true;
	int Ch[6] ={ 0 };
	for(int i=5; i>5-A[v][0]; i--) Ch[i] = 2;
	for(int i=5-A[v][0]; i>5-A[v][1]-A[v][0]; i--) Ch[i] = 1;
	int sum = 0;
	for(int i=0; i<3; i++) sum += A[v][i];
	if(sum != 5-v) return false;
	do 
	{
		bool flag = true;
		for(int i=v+1; i<6; i++) if(--A[i][Ch[i]] < 0) flag = false;
		if(flag == true) if(getCan(v+1)) return true;
		for(int i=v+1; i<6; i++) A[i][Ch[i]]++;
	} while(next_permutation(Ch+v+1, Ch+6));
	return false;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC = 4;
	while(TC--)
	{
		for(int i=0; i<6; i++) for(int j=0; j<3; j++) scanf("%d", &A[i][j]);
		printf("%d ", (int)getCan(0));
	}
	return 0;
}