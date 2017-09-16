#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 30;

int N, Rect[MAX_N][4], Pt[MAX_N][2];
bool isBetween(int x, int minX, int maxX)
{
	return x > minX && x < maxX;
}
bool isInside(int i, int j)
{
	bool x = isBetween(Pt[j][0], Rect[i][0], Rect[i][1]);
	bool y = isBetween(Pt[j][1], Rect[i][2], Rect[i][3]);
	return x & y;
}
vector<int> Edge[MAX_N]; //point -> Rect
bool isUnique[MAX_N];
void makeGraph()
{
	for(int i=1; i<=N; i++) for(int j=0; j<4; j++) scanf("%d", &Rect[i][j]);
	for(int i=1; i<=N; i++) for(int j=0; j<2; j++) scanf("%d", &Pt[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(isInside(i, j)) Edge[j].push_back(i);
}
void deleteGraph()
{
	for(int i=1; i<=N; i++)
	{
		vector<int> temp;
		Edge[i].swap(temp);
	}
}
bool Visit[MAX_N]; int Match[MAX_N];
bool findMatch(int v)
{
	if(Visit[v]) return false;
	Visit[v] = true;
	for(int i=0; i<Edge[v].size(); i++)
	{
		int w = Edge[v][i];
		if(Match[w] == 0 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	}
	return false;
}
bool findOther(int v, int lastMatch)
{
	if(Visit[v]) return false;
	Visit[v] = true;
	for(int i=0; i<Edge[v].size(); i++)
	{
		int w = Edge[v][i];
		if(Match[w] != v && (Match[w] == lastMatch || findOther(Match[w], lastMatch)))
			return true;
	}
	return false;
}
int main()
{
	int tc = 0;
	while(scanf("%d", &N) == 1)
	{
		if(N == 0) break;
		if(tc > 0) printf("\n");
		printf("Heap %d\n", ++tc);
		makeGraph();
		for(int i=1; i<=N; i++) Match[i] = 0;
		int flow = 0; bool isCan = true;
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++) Visit[j] = false;
			if(findMatch(i)) flow++;
		}
		for(int i=1; i<=N; i++) isUnique[i] = true;
		if(isCan) for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++) Visit[j] = false;
			if(findOther(i, i)) isUnique[i] = false;
		}
		deleteGraph();
		int cnt = 0;
		for(int i=1; i<=N; i++) 
			if(isUnique[Match[i]])
				printf("(%c,%d) ", 'A'+i-1, Match[i]), cnt++;
		if(cnt == 0) printf("none");
		printf("\n");
	}
	return 0;
}