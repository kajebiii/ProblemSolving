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
		int P, M, F, C;
		scanf("%d%d%d%d", &P, &M, &F, &C);
		int other = (M / P) * C / F;
		int cou = (M / P) * C % F + other * C;
		int ans = 0;
		while(cou >= F)
		{
			ans += cou / F;
			int plus = (cou / F * C);
			cou %= F; cou += plus;
		}
		printf("%d\n", ans);
	}
	return 0;
}
