#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 1e6 + 100;

int Cnt[MAX_N], N, M;
vector<int> List[MAX_N];
int main() {
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) for(int j=0, x; j<M; j++) 
		scanf("%d", &x), List[i].push_back(x);

	int cnt = 0;
	for(int j=0; j<M; j++) {
		for(int i=0; i<N; i++)
			if(++Cnt[List[i][j]] == N) cnt++;
		if(cnt == (j+1)) break;
	}
	printf("%d\n", cnt);
	for(int i=1; i<=M; i++) if(Cnt[i] == N) printf("%d ", i);
	return 0;
}