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

int Nr[7];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	for(int i=0; i<7; i++) scanf("%d", &Nr[i]);
	for(int i=4; i<7; i++)
	{
		int a = Nr[i] - 1;
		int ans = 0;
		for(int j=0; j<4; j+=2)
			if(a % (Nr[j] + Nr[j+1]) < Nr[j]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}