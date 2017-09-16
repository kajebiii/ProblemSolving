#include <stdio.h>
#include <vector>

using namespace std;

int N; char FN[99], LN[99];
vector<int> Edge[99];
bool Visit[99]; int Match[99];
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
	while(scanf("%d", &N) == 1)
	{
		if(N == 0) break;
		for(int i=0; i<N; i++)
		{
			scanf("%s%s", FN, LN);
			Edge[FN[0] - 'A' + 1].push_back(LN[0] - 'A' + 1);
		}
		int flow = 0;
		for(int i=1; i<=26; i++) Match[i] = 0;
		for(int i=1; i<=26; i++)
		{
			for(int j=1; j<=26; j++) Visit[j] = false;
			if(findMatch(i)) flow++;
		}
		printf("%d\n", flow);
		for(int i=1; i<=26; i++)
		{
			vector<int> temp;
			Edge[i].swap(temp);
		}
	}
	return 0;
}