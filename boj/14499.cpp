#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 22;

int N, M, Nr[MAX_N][MAX_N], K, X, Y;
vector<int> Dice = vector<int>(6, 0);
int Wh[6][4] ={
	{3, 2, 1, 4},
	{1, 1, 5, 0},
	{0, 5, 2, 2},
	{5, 0, 3, 3},
	{4, 4, 0, 5},
	{2, 3, 4, 1},
};
int main() {
	scanf("%d%d%d%d%d", &N, &M, &X, &Y, &K);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &Nr[i][j]);
	while(K--) {
		int d;
		scanf("%d", &d); d--;
		int nX = X + "1102"[d] - '1';
		int nY = Y + "2011"[d] - '1';
		if(nX < 0 || nX >= N || nY < 0 || nY >= M) continue;
		vector<int> next = Dice;
		for(int i=0; i<6; i++) next[i] = Dice[Wh[i][d]];
		Dice = next;
		X = nX, Y = nY;
		if(Nr[X][Y] == 0) Nr[X][Y] = Dice[5];
		else Dice[5] = Nr[X][Y], Nr[X][Y] = 0;
		printf("%d\n", Dice[0]);
	}
	return 0;
}