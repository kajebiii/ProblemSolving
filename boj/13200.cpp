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

int N, Nr[9][9], Ix[9][9][2], IxN[2]; // -- / ||
int Chk[2][81]; bool Last[9][9][2];
int Ans[9][9]; bool Find = false;
void findAns(int x, int y)
{
	if(x == N+2)
	{
		for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) if(Nr[i][j] == -2)
			if(Chk[0][Ix[i][j][0]] == false && Chk[1][Ix[i][j][1]] == false) return;
		for(int i=1; i<=N; i++, puts("")) for(int j=1; j<=N; j++)
			printf("%d ", Ans[i][j]);
		Find = true;
		return;
	}
	if(y == N+1) 
	{
		return findAns(x+1, 1);
	}
	if(Nr[x][y] >= -1)
	{
		if(Nr[x-1][y] > 0) return;
		Ans[x][y] = 0;
		return findAns(x, y+1);
	}
	// 0
	for(int k=0; k<1; k++)
	{
		if(Nr[x-1][y] > 0) continue;
		Ans[x][y] = 0;
		findAns(x, y+1); if(Find) return;
	}
	// 1
	for(int k=0; k<1; k++)
	{
		
		bool flag = false;
		for(int l=0; l<2; l++)
			if(Chk[l][Ix[x][y][l]] == 1) flag = true;
		if(flag) continue;
		if(Nr[x-1][y] >= 2) continue;
		
		for(int l=0; l<4; l++)
		{
			int nx = x + Ch[l].fi, ny = y + Ch[l].se;
			if(Nr[nx][ny] == 0) {flag = true; break;}
		}
		if(flag) continue;
		
		for(int l=0; l<4; l++)
		{
			int nx = x + Ch[l].fi, ny = y + Ch[l].se;
			if(Nr[nx][ny] > 0) Nr[nx][ny]--; 
		}
		for(int l=0; l<2; l++) Chk[l][Ix[x][y][l]]++;
		Ans[x][y] = 1;
		findAns(x, y+1); 
		for(int l=0; l<4; l++)
		{
			int nx = x + Ch[l].fi, ny = y + Ch[l].se;
			if(Nr[nx][ny] >= 0) Nr[nx][ny]++; 
		}
		for(int l=0; l<2; l++) Chk[l][Ix[x][y][l]]--;
		if(Find) return;
	}

}
int main()
{
	int T; cin >> T;
	while(T--)
	{
		scanf("%d", &N); for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &Nr[i][j]);
		for(int i=1; i<=N; i++) Nr[0][i] = Nr[N+1][i] = Nr[i][0] = Nr[i][N+1] = -1;
		for(int i=0; i<2; i++) IxN[i] = 0;
		for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) for(int k=0; k<2; k++)
			Ix[i][j][k] = 0, Last[i][j][k] = false;
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N+1; j++)
				if(Nr[i][j] == -2) 
				{
					Ix[i][j][0] = IxN[0];
					if(Nr[i][j+1] >= -1) Last[i][j][0] = true;
				}else if(Nr[i][j-1] == -2) IxN[0]++;
			for(int j=1; j<=N+1; j++)
				if(Nr[j][i] == -2) 
				{
					Ix[j][i][1] = IxN[1];
					if(Nr[j+1][i] >= -1) Last[i][j][1] = true;
				}else if(Nr[j-1][i] == -2) IxN[1]++;
		}
		Find = false;
		findAns(1, 1);
	}
	return 0;
}
