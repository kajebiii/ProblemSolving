/*
#include <stdio.h>
#include <set>

using namespace std;

const int TEST_N = 1e3 + 10;

int Gr[TEST_N][TEST_N];
int getGr(int n, int p)
{
	if(p > n) p = n;
	return Gr[n][p];
}
int main()
{
	Gr[0][0] = 0; Gr[1][1] = 1;
	for(int i=2; i<=40; i++)
	{
		printf("[%02d] : ", i);
		for(int j=1; j<=i; j++)
		{
			set<int> S;
			for(int k=1; k<=j; k++)
				S.insert(getGr(i-k, k*2));
			S.insert(0x7fffffff);
			int k = -1;
			for(int x : S)
			{
				if(k+1 != x) {k = k+1; break;}
				else k = k+1;
			}
			Gr[i][j] = k;
			printf("%d ", k);
		}
		for(int k=1; k<=i-1; k++)
			if(getGr(i-k, k*2) == 0)
			{
				printf(">> %d", k);
				break;
			}
		printf("\n");
	}
	int last = 0;
	for(int i=2; i<=500; i++)
		if(Gr[i][i-1] == 0) 
		{
//			printf("%4d %4d\n", i, i - last);
			last = i;
		}
	return 0;
}
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6;

int Chk[MAX_N+1];
vector<int> F;
int main()
{
	F.push_back(1);
	F.push_back(1);
	int FN = 2;
	while(1)
	{
		int now = F[FN-1] + F[FN-2];
		if(now > MAX_N * 2) break;
		F.push_back(now);
		FN++;
	}
	int N; scanf("%d", &N);
	int tempN = N, K;
	while(1)
	{
		K = F[upper_bound(F.begin(), F.end(), tempN) - F.begin() - 1];
		if(K == tempN) break;
		tempN -= K;
	}
	if(K == N) printf("-1");
	else printf("%d", K);
	return 0;
}
