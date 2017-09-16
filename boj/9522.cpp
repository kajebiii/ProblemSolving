#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> GA, GB;
vector<int> Edge[555];

bool Visit[555]; int Match[555];
bool findMatch(int v)
{
	if(Visit[v] == true) return false;
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
	scanf("%d", &N);
	for(int i=0, x, y; i<N; i++)
	{
		scanf("%d%d", &x, &y), Edge[x].push_back(y);
		GA.push_back(x); GB.push_back(y);
	}
	sort(GA.begin(), GA.end());
	sort(GB.begin(), GB.end());
	GA.resize(unique(GA.begin(), GA.end()) - GA.begin());
	GB.resize(unique(GB.begin(), GB.end()) - GB.begin());
	int ans = 0;
	for(int i : GA)
	{
		for(int j : GA) Visit[j] = false;
		if(findMatch(i)) ans++;
	}
	if((int)0 + GA.size() + GB.size() - ans * 2 > 0) puts("Mirko");
	else puts("Slavko");
	return 0;
}