#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 20;

int N; ll L, D[MAX_N][MAX_N];
int Ch[MAX_N];
int main()
{
	scanf("%d%lld", &N, &L);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%lld", &D[i][j]);
	Ch[0] = -1; Ch[1] = 0;
	for(int i=2; i<2+(N-2)/2; i++) Ch[i] = 1;
	for(int i=2+(N-2)/2; i<N; i++) Ch[i] = 2;
	
	bool isCan = false;
	do
	{
		vector<int> l[2];
		for(int i=1; i<N; i++) if(Ch[i] == 1 || Ch[i] == 2)
			l[Ch[i] - 1].push_back(i);
		int who = -1;
		for(int i=1; i<N; i++) if(Ch[i] == 0) who = i;
		int se[2][2] = { {who, 0}, {0, who} };

		vector<ll> val[2];
		for(int k=0; k<2; k++)
		{
			sort(l[k].begin(), l[k].end());
			do
			{
				int past = se[k][0]; ll now = 0;
				for(int x : l[k])
				{
					now += D[past][x];
					past = x;
				}
				now += D[past][se[k][1]];
				val[k].push_back(now);
			}while(next_permutation(l[k].begin(), l[k].end()));
			sort(val[k].begin(), val[k].end());
		}

		int j = (int)val[1].size() - 1;
		for(ll x : val[0])
		{
			while(x+val[1][j] > L && j > 0) j--;
			if(x + val[1][j] == L) isCan = true;
		}
		if(isCan) break;
	}while(next_permutation(Ch+1, Ch+N));

	if(isCan) puts("possible");
	else puts("impossible");
	return 0;
}