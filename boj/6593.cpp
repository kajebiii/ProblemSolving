#include <stdio.h>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

typedef tuple<int, int, int> ti;
#define mt make_tuple

const int MAX_H = 4e1;

int L, R, C;
char Mp[MAX_H][MAX_H][MAX_H];
map<ti, int> Dis;
map<ti, int> Chk;

ti S, E, Ch[6] = {mt(-1, 0, 0), mt(+1, 0, 0), mt(0, -1, 0), mt(0, +1, 0), mt(0, 0, -1), mt(0, 0, +1)};
ti operator+(const ti &a, const ti &b)
{
	int a_[3], b_[3];
	tie(a_[0], a_[1], a_[2]) = a;
	tie(b_[0], b_[1], b_[2]) = b;
	for(int k=0; k<3; k++) a_[k] += b_[k];
	return mt(a_[0], a_[1], a_[2]);
}

int main()
{
	while(scanf("%d%d%d", &L, &R, &C) == 3)
	{
		Dis.clear();
		Chk.clear();
		if(L + R + C == 0) break;
		for(int i=0; i<L; i++) for(int j=0; j<R; j++) scanf("%s", Mp[i][j]);
		for(int i=0; i<L; i++) for(int j=0; j<R; j++) for(int k=0; k<C; k++)
		{
			if(Mp[i][j][k] == 'S')
				S = mt(i, j, k), Mp[i][j][k] = '.';
			else if(Mp[i][j][k] == 'E')
				E = mt(i, j, k), Mp[i][j][k] = '.';
		}

		queue<ti> Q; Q.push(S); Dis[S] = 1;
		while(!Q.empty())
		{
			ti now = Q.front(); Q.pop();
			int a, b, c; tie(a, b, c) = now;
			for(int k=0; k<6; k++)
			{
				ti next = now + Ch[k];
				int x, y, z; tie(x, y, z) = next;
				if(x<0||y<0||z<0||x>=L||y>=R||z>=C) continue;
				if(Dis[next] != 0) continue; 
				if(Mp[x][y][z] == '#') continue;
				Dis[next] = Dis[now]+1;
				Q.push(next);
			}
		}
		if(Dis[E] == 0) puts("Trapped!");
		else printf("Escaped in %d minute(s).\n", Dis[E]-1);
	}
	return 0;
}