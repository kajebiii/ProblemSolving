#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, C[111][111], Dy[111][111];

int main() {
	scanf("%d", &N);
	for(int i=0, x, y; i<N; i++) {
		scanf("%d%d", &x, &y);
		if(x > y) swap(x, y);
		C[x][y] = 1;
	}
	for(int i=1; i<=99; i++)
		for(int j=1; j+i<=100; j++)
			for(int k=j; k<j+i; k++)
				Dy[j][j+i] = max(Dy[j][j+i], Dy[j][k] + Dy[k+1][j+i] + C[j][j+i]);
	printf("%d\n", Dy[1][100]);
	return 0;
}