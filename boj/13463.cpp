#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 2e5 + 100;

int N, M, X, L;
vector<int> Ed[MAX_N];
int Cnt[MAX_N], All[MAX_N];
bool Chk[MAX_N];

int main() {
	scanf("%d%d%d%d", &N, &M, &X, &L);
	for(int i=0; i<M; i++) {
		int x, y; scanf("%d%d", &x, &y);
		Ed[x].push_back(y), Ed[y].push_back(x);
		All[x] = ++Cnt[x]; All[y] = ++Cnt[y];
	}
	queue<int> Q; Q.push(L); Chk[L] = true;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		for(int w : Ed[v]) {
			if(--Cnt[w] <= All[w] / 2 && Chk[w] == false) {
				Chk[w] = true;
				Q.push(w);
			}
		}
	}
	if(Chk[X]) puts("leave");
	else puts("stay");
	return 0;
}