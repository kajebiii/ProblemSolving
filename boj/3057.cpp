#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 303;

int N, M, Nr[MAX_N][MAX_N];

void getInput()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%1d", &Nr[i][j]);
}

bool Dy[3][MAX_N][MAX_N];
void process()
{
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) for(int k=0; k<2; k++)
		Dy[k][i][j] = true;
	int maxS = min(N, M), ans = 1;
	for(int s=2; s<=maxS; s++)
	{
		int bs = (s-2) % 3;
		for(int i=1; i+s-1<=N; i++) for(int j=1; j+s-1<=M; j++) 
		{
			if(Dy[bs][i+1][j+1] == false)
			{
				Dy[s%3][i][j] = false;
				continue;
			}
			bool flag = true;
			for(int k=0; k<s; k++)
			{
				if(Nr[i][j+k] != Nr[i+s-1][j+s-1-k]) { flag = false; break; }
				if(Nr[i+k][j] != Nr[i+s-1-k][j+s-1]) { flag = false; break; }
			}
			Dy[s%3][i][j] = flag;
			if(flag) ans = s;
		}
	}
	printf("%d\n", ans==1?-1:ans);
}
int main()
{
	getInput();
	process();
	return 0;
}