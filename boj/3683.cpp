#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 555;

int Ani[2], Grp[2], Nr[MAX_N][2];
vector<int> Edge[MAX_N];
bool Visit[MAX_N]; int Match[MAX_N];
bool findMatch(int v)
{
	if(Visit[v] == true) return false;
	Visit[v] = true;
	for(int w : Edge[v])
		if(Match[w] == -1 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}
int main()
{
//	freopen("input.txt", "r", stdin);
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		for(int k=0; k<2; k++) scanf("%d", &Ani[k]);
		int N; scanf("%d\n", &N);
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<2; j++)
			{
				char x; int y;
				scanf("%c%d ", &x, &y);
				Nr[i][j] = (x-'C') * 200 + y;
			}
			for(int j=0; j<i; j++)
				if(Nr[i][0] == Nr[j][1] || Nr[i][1] == Nr[j][0])
					Edge[i].push_back(j), Edge[j].push_back(i);
		}
		for(int i=0; i<N; i++) Match[i] = -1;

		int ans = 0;
		for(int i=0; i<N; i++)
		{
			if(Nr[i][1] < 200) continue;
			for(int j=0; j<N; j++) Visit[j] = false;
			if(findMatch(i)) ans++;
		}
		printf("%d\n", N - ans);
		
		for(int i=0; i<N; i++) 
		{
			vector<int> temp;
			Edge[i].swap(temp);
		}
	}
	return 0;
}