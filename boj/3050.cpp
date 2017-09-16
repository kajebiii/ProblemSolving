#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <tuple>

using namespace std;

const int MAX_N = 4e2 + 10, debug = 1;

typedef pair<int, int> pi;

int N, M, Nr[MAX_N][MAX_N];
void getInput()
{
	scanf("%d%d", &N, &M); 
	for(int i=1; i<=N; i++)
	{
		scanf(" ");
		for(int j=1; j<=M; j++)
		{
			char x; scanf("%c", &x);
			if(x == 'X') Nr[i][j] = 0;
			else Nr[i][j] = Nr[i-1][j] + 1;
		}
	}
}
int main()
{
	getInput();
	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		stack<pi> S;
		S.push(make_pair(0, 0));
		int j = 1;
		while(j <= M+1)
		{
			int lx, lh; tie(lx, lh) = S.top();
			if(lh <= Nr[i][j])
			{
				S.push(make_pair(j, Nr[i][j]));
				j++;
			}
			else
			{
				S.pop();
				int llx, llh; tie(llx, llh) = S.top();
				int x = (j - (llx + 1)), h = lh;
				ans = max(ans, x * 2 + h * 2);
			}
		}
	}
	printf("%d\n", ans-1);
	return 0;
}