#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e1 + 10;

int N, M;
char Mp[MAX_N][MAX_N];
int Dy[MAX_N][MAX_N], State[MAX_N][MAX_N];

int getDy(int x, int y)
{
	if(State[x][y] == 2) return Dy[x][y];
	if(State[x][y] == 1) return -1;
	State[x][y] = 1;
	int val = 1;
	if(Mp[x][y] == 'H') {State[x][y] = 2; return Dy[x][y] = 0;}
	int ch[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	int now = Mp[x][y] - '0';
	for(int k=0; k<4; k++)
	{
		int nx = x + ch[k][0] * now, ny = y + ch[k][1] * now;
		if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if(getDy(nx, ny) == -1) {State[x][y] = 2; return Dy[x][y] = -1;}
		val = max(val, getDy(nx, ny) + 1);
	}
	State[x][y] = 2;
	return Dy[x][y] = val;
}

int main()
{
	scanf("%d%d", &N, &M); 
	for(int i=0; i<N; i++) scanf("%s", Mp[i]);
	printf("%d\n", getDy(0, 0));
	return 0;
}