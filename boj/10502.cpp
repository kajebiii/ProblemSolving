#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 10;
typedef pair<int, int> pi;

vector<int> Edge[MAX_N];
pi PathMemo[MAX_N * MAX_N];
int N, K;
bool Path[MAX_N][MAX_N];
void getInput()
{
	scanf("%d", &N);
	for(int i=1, x, y; i<N; i++)
		scanf("%d%d", &x, &y), Edge[x].push_back(y), Edge[y].push_back(x);
	scanf("%d", &K);
	for(int i=1, x, y; i<=K; i++)
	{
		scanf("%d%d", &x, &y);
		PathMemo[i] = make_pair(x, y);
		Path[x][y] = Path[y][x] = true;
	}
}
vector<int> unUse[MAX_N];
bool Graph[MAX_N][MAX_N];
int Dy[1 << 10];
int getAns(int v, int p)
{
	int result = 0;
	vector<int> ws;
	for(int w : Edge[v])
		if(w != p)
		{
			result += getAns(w, v);
			ws.push_back(w);
		}
	for(int w : ws)
		for(int x : unUse[w])
			if(Path[x][v])
			{
				result++;
				unUse[w].clear();
				unUse[w].shrink_to_fit();
				break;
			}
	for(int a : ws) for(int b : ws)
		if(a != b) for(int x : unUse[a]) for(int y : unUse[b])
			if(Path[x][y]) Graph[a][b] = Graph[b][a] = true;
	
	Dy[0] = 0;
	for(int i=1; i<(1<<ws.size()); i++)
	{
		Dy[i] = Dy[i - (-i & i)];
		for(int a=0; a<ws.size(); a++) if(i & (1<<a))
			for(int b=a+1; b<ws.size(); b++) if(i & (1<<b))
				if(Graph[ws[a]][ws[b]])
					Dy[i] = max(Dy[i], Dy[i - (1<<a) - (1<<b)] + 1);
	}
	int all = (1<<ws.size()) - 1;
	result += Dy[all];
	unUse[v].push_back(v);
	for(int i=0; i<ws.size(); i++)
		if(Dy[all] == Dy[all - (1<<i)])
			for(int x : unUse[ws[i]])
				unUse[v].push_back(x);
	return result;
}
void doClear()
{
	for(int i=1; i<=N; i++) Edge[i].clear(), Edge[i].shrink_to_fit();
	for(int i=1; i<=N; i++) unUse[i].clear(), unUse[i].shrink_to_fit();
	for(int i=1, x, y; i<=K; i++)
	{
		x = PathMemo[i].first, y = PathMemo[i].second;
		Path[x][y] = Path[y][x] = false;
	}
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) Graph[i][j] = false;
}
int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		getInput();
		printf("%d\n", getAns(1, -1));
		doClear();
	}
	return 0;
}