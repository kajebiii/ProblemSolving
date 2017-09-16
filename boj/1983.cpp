#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 5e2 + 10, INF = 0x7ffffff;

int N, Dy[2][MAX_N][MAX_N];
vector<int> L[2];

int main()
{
	scanf("%d", &N); 
	L[0].resize(1); L[1].resize(1);
	for(int k=0; k<2; k++) for(int i=0, x; i<N; i++) 
	{
		scanf("%d", &x);
		if(x != 0) L[k].push_back(x);
	}
	int LN[2] = {L[0].size() - 1, L[1].size() - 1};
	
	for(int i=0; i<=LN[0]; i++) for(int j=0; j<=LN[1]; j++) Dy[1][i][j] = -INF;
	Dy[1][0][0] = 0;
	for(int n=0; n<N; n++)
	{
		int no = n%2, pa = 1-n%2;
		for(int i=LN[0]; i>=0; i--) for(int j=LN[1]; j>=0; j--)
			Dy[no][i][j] = -INF;
		for(int i=LN[0]; i>=0; i--) for(int j=LN[1]; j>=0; j--)
		{
			if(i>0 && j>0 && Dy[pa][i-1][j-1] != -INF) Dy[no][i][j] = max(Dy[no][i][j], Dy[pa][i-1][j-1] + L[0][i] * L[1][j]);
			if(j>0 && Dy[pa][i  ][j-1] != -INF) Dy[no][i][j] = max(Dy[no][i][j], Dy[pa][i][j-1]);
			if(i>0 && Dy[pa][i-1][j  ] != -INF) Dy[no][i][j] = max(Dy[no][i][j], Dy[pa][i-1][j]);
			if(Dy[pa][i  ][j  ] != -INF) Dy[no][i][j] = max(Dy[no][i][j], Dy[pa][i  ][j]);
		}
	}
	printf("%d", Dy[1-N%2][LN[0]][LN[1]]);
	return 0;
}