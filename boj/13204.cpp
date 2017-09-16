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
#define mp make_pair
#define fi first
#define se second
#define pb push_back

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, 1), mp(1, 0), mp(0, -1)};

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int a, b; scanf("%d.%d", &a, &b);
		int x = a*1000 + b; x*=10;
		int sx = x-5, bx = x+5;
		int under = 1000000;

		for(int i=1; i<=1000000; i++)
		{
			ll left = 1ll * sx * i, right = 1ll * bx * i;
			int l = (left - 1) / 1000000 + 1, r = (right - 1) / 1000000;
			if(l <= r) 
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
