#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 55, MAX_V = MAX_N * MAX_N;

int N, M; char Mp[MAX_N][MAX_N];
struct PT
{
	int x, y;
	PT():x(0), y(0){}
	PT(int a, int b):x(a), y(b) {}
	PT operator+(PT other) {return PT(x+other.x, y+other.y); }

	int to() {return x;}
	int cost() {return y;}
};
PT Ch[4] = {PT(0, 1), PT(0, -1), PT(1, 0), PT(-1, 0)};

int CntN[2]; char baseC[2] = {'C', 'P'};
int Value[MAX_N][MAX_N], Chk[MAX_N][MAX_N];
vector<PT> Edge[MAX_N*MAX_N];
void doInit()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%s", Mp[i]+1);
	for(int i=1; i<=N; i++) Mp[i][0] = Mp[i][M+1] = 'X';
	for(int i=1; i<=M; i++) Mp[0][i] = Mp[N+1][i] = 'X';

	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) for(int k=0; k<2; k++)
		if(Mp[i][j] == baseC[k]) Value[i][j] = ++CntN[k];

	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		if(Mp[i][j] != 'C') continue;
		for(int x=1; x<=N; x++) for(int y=1; y<=M; y++) Chk[x][y] = 0;
		queue<PT> Q; Q.push(PT(i, j)); Chk[i][j] = 1;
		while(!Q.empty())
		{
			PT now = Q.front(); Q.pop();
			if(Mp[now.x][now.y] == 'P')
				Edge[Value[i][j]].push_back(PT(Value[now.x][now.y], Chk[now.x][now.y]-1));
			for(int k=0; k<4; k++)
			{
				PT next = now + Ch[k];
				if(Mp[next.x][next.y] == 'X') continue;
				if(Chk[next.x][next.y] != 0) continue;
				Q.push(next); Chk[next.x][next.y] = Chk[now.x][now.y]+1;
			}
		}
	}
}

bool Visit[MAX_N * MAX_N]; int Match[MAX_N * MAX_N];
bool findMatch(int v, int maxC)
{
	if(Visit[v] == true) return false;
	Visit[v] = true;
	for(PT &next : Edge[v])
	{
		int w = next.to(), c = next.cost();
		if(c > maxC) continue;
		if(Match[w] == 0 || findMatch(Match[w], maxC))
		{
			Match[w] = v;
			return true;
		}
	}
	return false;
}
int main()
{
	doInit();

	int result = -1;
	for(int l = 0, r = MAX_N * MAX_N; l < r; )
	{
		int m = (l + r) >> 1;
		int now = 0;
		for(int j=1; j<=CntN[1]; j++) Match[j] = 0;
		for(int i=1; i<=CntN[0]; i++)
		{
			for(int j=1; j<=CntN[0]; j++) Visit[j] = false;
			if(findMatch(i, m)) now++;
		}
		if(now == CntN[0]) r = m;
		else l = m+1;
		result = l;
	}
	if(result == MAX_N * MAX_N) result = -1;
	printf("%d\n", result);
	return 0;
}