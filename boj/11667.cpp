#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <string.h>

using namespace std;

typedef pair<int, int> pi;

const int MAX_N = 2e2 + 10;

int N, P;
vector<pi> All;
vector<pi> cover, other;
int Dy[MAX_N][MAX_N], Sum[MAX_N];

int main()
{
	scanf("%d%d", &N, &P);
	for(int i=0, x, y; i<N; i++) scanf("%d%d", &x, &y), All.push_back(make_pair(x, y));
	for(int i=0; i<N; i++)
	{
		bool isCover = false;
		for(int j=0; j<N; j++)
		{
			if(i == j) continue;
			if(All[i].first < All[j].first && All[j].second < All[i].second)
				isCover = true;
		}
		if(isCover) cover.push_back(All[i]);
		else other.push_back(All[i]);
	}
	other.push_back(make_pair(-1, -1)); // for 1 base
	sort(other.begin(), other.end());
	int oN = other.size() - 1;

	memset(Dy, 0xff, sizeof(Dy));
	Dy[0][0] = 0;
	for(int i=1; i<=oN; i++) for(int j=1; j<=P; j++) for(int k=i; k>=1; k--)
	{
		if(other[k].second <= other[i].first) break;
		if(Dy[k-1][j-1] != -1)
			Dy[i][j] = max(Dy[i][j], Dy[k-1][j-1] + other[k].second - other[i].first);
	}
	int cN = cover.size();
	for(int i=0; i<cN; i++)
		Sum[i+1] = cover[i].second - cover[i].first;
	sort(Sum+1, Sum+cN+1, greater<int>());
	for(int i=1; i<=cN; i++) Sum[i] += Sum[i-1];

	int ans = 0;
	for(int j=0; j<=min(P-1, cN); j++)
		if(Dy[oN][P-j] != -1)
			ans = max(ans, Sum[j] + Dy[oN][P-j]);

//	for(int i=1; i<=oN; i++) for(int j=1; j<=P; j++) printf("%d %d : %d\n", i, j, Dy[i][j]);
	printf("%d\n", ans);
	return 0;
}