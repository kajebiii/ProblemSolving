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

const int MAX_N = 1e6 + 100;

int Nr[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int x;
	while(scanf("%d", &x) == 1)
	{
		x *= 10000000;
		int N; scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		sort(Nr, Nr+N);
		int r = N-1; bool flag = false;
		for(int l=0; l<r; l++)
		{
			while(r > 0 && Nr[l] + Nr[r] > x) r--;
			if(Nr[l] + Nr[r] == x && l < r)
			{
				flag = true;
				printf("yes %d %d\n", Nr[l], Nr[r]);
				break;
			}
		}
		if(flag == false) puts("danger");
	}
	return 0;
}