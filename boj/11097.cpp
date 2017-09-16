#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e2 + 10;

int N, UNF[MAX_N], P[MAX_N][MAX_N];
int F(int v) {return UNF[v]==v?v:UNF[v]=F(UNF[v]);}
void U(int a, int b) {UNF[F(a)] = F(b); }
vector<int> V[MAX_N]; int AnsP[MAX_N][MAX_N];
int main()
{
	int T; scanf("%d", &T);
	for(int _=0; _<T; _++)
	{
		scanf("%d", &N);
		for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
			scanf("%1d", &P[i][j]);
		for(int i=1; i<=N; i++) UNF[i] = i;
		for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++)
			if(P[i][j] == P[j][i] && P[i][j]) U(i, j);
		for(int i=1; i<=N; i++) V[F(i)].push_back(i);
		vector<int> L;
		vector<pair<int, int> > Ans;
		for(int i=1; i<=N; i++) if(V[i].size() != 0) L.push_back(i);
		for(int i=1; i<=N; i++) if(V[i].size() > 1)
			for(int j=0; j<V[i].size(); j++)
				Ans.push_back(make_pair(V[i][j], V[i][(j+1)%V[i].size()]));
		for(int &x : L) P[x][x] = 0;
		for(int &x : L) for(int &y : L) AnsP[x][y] = P[x][y];
		for(int &x : L) for(int &y : L) if(P[x][y]) for(int &z : L)
			if(P[y][z]) AnsP[x][z] = 0;
		for(int &x : L) for(int &y : L) if(AnsP[x][y])
			Ans.push_back(make_pair(x, y));
		if(_ != 0) puts("");
		printf("%d\n", Ans.size());
		for(auto l : Ans)
			printf("%d %d\n", l.first, l.second);

		for(int i=1; i<=N; i++)
		{
			vector<int> temp;
			V[i].swap(temp);
		}
	}
	return 0;
}