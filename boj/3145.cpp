#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

typedef pair<int, int> pi;
const int MAX_N = 55;

int N, M; char Mp[MAX_N][MAX_N];
string St[MAX_N*MAX_N]; pi Pt[MAX_N*MAX_N];
int StN, PtN;
vector<int> Edge[MAX_N*MAX_N];
map<pi, int> Memo;
void makeGraph()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%s", Mp[i]+1);
	for(int i=0; i<=N+1; i++) Mp[i][0] = Mp[i][M+1] = '.';
	for(int i=0; i<=M+1; i++) Mp[0][i] = Mp[N+1][i] = '.';
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		if(Mp[i][j] == 'x') Memo[Pt[++PtN] = make_pair(i, j)] = PtN;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		if(Mp[i][j] >= 'A' && Mp[i][j] <= 'Z' && (Mp[i][j+1] == '.' || Mp[i][j+1] == 'x') )
		{
			int r = j, l = j;
			while(l > 1 && Mp[i][l-1] >= 'A' && Mp[i][l-1] <= 'Z') l--;
			++StN;
			for(int k=l; k<=r; k++) St[StN] += string(1, Mp[i][k]);
			for(int x=i-1; x<=i+1; x++) for(int y=l-1; y<=r+1; y++)
			{
				if(x == i && y >= l && y <= r) continue;
				if(Mp[x][y] == 'x')
					Edge[StN].push_back(Memo[make_pair(x, y)]);
			}
		}
}

bool Visit[MAX_N*MAX_N]; int Match[MAX_N*MAX_N];
bool findMatch(int v)
{
	if(Visit[v]) return false;
	Visit[v] = true;
	for(int w : Edge[v])
		if(Match[w] == 0 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}
int main()
{
	makeGraph();
	int flow = 0;
	for(int i=1; i<=StN; i++)
	{
		for(int j=1; j<=StN; j++) Visit[j] = false;
		if(findMatch(i)) flow++;
	}
	for(int i=1; i<=PtN; i++)
		cout << Pt[i].first << ' ' << Pt[i].second << ' ' << St[Match[i]] << endl;
	return 0;
}