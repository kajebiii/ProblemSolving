#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 100, INF = 0x7fffffff;

int N, Nr[MAX_N];
vector<int> Ed[MAX_N];

int Dy[MAX_N][3];

void getDy(int v, int p) {
	int cnt = 0;
	for(int w : Ed[v]) if(w != p)
		getDy(w, v), cnt++;
	if(cnt == 0) {
		Dy[v][0] = -INF;
		Dy[v][1] = 0;
		Dy[v][2] = Nr[v];
	}else{
		int countTwo = 0, minV = INF;
		Dy[v][2] = Nr[v];
		for(int w : Ed[v]) if(w != p) {
			Dy[v][0] += Dy[w][1];
			Dy[v][2] += max(Dy[w][0],Dy[w][1]);
			if(Dy[w][2] >= Dy[w][1])
				Dy[v][1] += Dy[w][2],countTwo++;
			else{
				Dy[v][1] += Dy[w][1];
				minV = min(minV,Dy[w][1] - Dy[w][2]);
			}
		}
		if(countTwo == 0) Dy[v][1] -= minV;
	}
	return;
}

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
		scanf("%d", &Nr[i]);
	for(int i=1,x,y; i<N; i++) {
		scanf("%d%d", &x, &y);
		Ed[x].push_back(y);
		Ed[y].push_back(x);
	}
	getDy(1, 0);

	printf("%d\n", max(Dy[1][0], max(Dy[1][1], Dy[1][2])));

	return 0;
}