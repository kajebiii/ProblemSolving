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

const int MAX_N = 55;

int N, M, Chk[10], Rank[10];
char Map[MAX_N][MAX_N];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	
	cin >> N >> M;
	for(int i=1; i<=N; i++) scanf("%s", Map[i] + 1);
	int cnt = 1;
	for(int j=M; j>=1; j--)
	{
		bool flag = false;
		for(int i=1; i<=N; i++)
		{
			if(Map[i][j] < '1' || Map[i][j] > '9') continue;
			int now = Map[i][j] - '0';
			if(Chk[now] == 1) continue;
			flag = true;
			Chk[now] = 1;
			Rank[now] = cnt;
		}
		if(flag) cnt++;
	}
	for(int i=1; i<=9; i++) printf("%d\n", Rank[i]);
	return 0;
}