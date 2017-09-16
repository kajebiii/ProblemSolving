#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

const int MAX_N = (5e2 + 10) * 2;

typedef long double ld;

int Dis[MAX_N][MAX_N], N;
vector<int> Ed[MAX_N], Co[MAX_N];

void addEdge(int x, int y, int c)
{
	Ed[x].push_back(y); Co[x].push_back(c);
	Ed[y].push_back(x); Co[y].push_back(c);
}
void initGraph(vector<int> &nodes)
{
	int n = nodes.size();
//	printf("N : %d | ", n);for(int v : nodes) printf("%d ", v); puts("");
	if(n <= 1) return;

	map<int, vector<int> > mp;
	int x = nodes[0], y = nodes[1];
	if(n == 2) {addEdge(x, y, Dis[x][y]); return; }
	for(int i=0; i<n; i++)
	{
		int z = nodes[i];
		int fromX = (Dis[x][y] + Dis[x][z] - Dis[y][z]) / 2;
		mp[fromX].push_back(z);
	}

	int pastD = 0, pastN = x;
	for(auto &info : mp)
	{
		int nowD = info.first; vector<int> &same = info.second;
		int newN = N+1;
		for(int v : same) if(Dis[x][v] == nowD) newN = v;
		vector<int> next;
		if(newN == N+1) N++, next.push_back(newN);
		for(int v : same) Dis[newN][v] = Dis[v][newN] = Dis[x][v] - nowD;
		for(int v : same) next.push_back(v);
		initGraph(next);


		if(pastN != newN) addEdge(pastN, newN, nowD - pastD);
		pastD = nowD; pastN = newN;
	}
}

int S[MAX_N], allN;
tuple<ld, int> getAns(int v, int p)
{
	ld vval = 0; int vsize = 1;
	int n = Ed[v].size();
	for(int i=0; i<n; i++) if(Ed[v][i] != p)
	{
		int w = Ed[v][i], c = Co[v][i];
		ld wval; int wsize; tie(wval, wsize) = getAns(w, v);
		vval += wval;
		vsize += wsize + c - 1;
	}
	S[v] = vsize;

	for(int i=0; i<n; i++) if(Ed[v][i] != p)
	{
		int w = Ed[v][i], c = Co[v][i];
		int wsize = S[w], upsize = allN - S[w] - (c-1);
//		printf("%d : %d %d\n", v, wsize, upsize);
		vval += (ld)1.0 * wsize * upsize * c;
		vval += (ld)1.0 * (wsize + upsize) * c * (c-1) / 2;
		vval += (ld)1.0 * c * (c-1) * (c-2) / 6;
	}
//	printf("%d >> %d\n", v, S[v]);
	return make_tuple(vval, vsize);
}

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++) scanf("%d", &Dis[i][j]), Dis[j][i] = Dis[i][j];
	vector<int> base; for(int i=1; i<=N; i++) base.push_back(i);
	initGraph(base);
//	for(int i=1; i<=N; i++){printf("%d : ", i); for(int k=0; k<Ed[i].size(); k++) printf("[%d %d] ", Ed[i][k], Co[i][k]); puts("");}

	for(int i=1; i<=N; i++) for(int k=0; k<Ed[i].size(); k++) allN += (Co[i][k] - 1);
	allN = (allN / 2) + N;

	tuple<ld, int> val = getAns(1, 0);
	ld ans; int temp; tie(ans, temp) = val;
	printf("%.12Lf\n", ans / ((ld)allN * (allN-1) / 2));
	return 0;
}