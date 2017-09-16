#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 1e3 + 10, MAX_NR = 5e4, MOD = 1e9;

bool notP[MAX_NR+1];
vector<int> Ps;
int Cnt[MAX_NR]; map<int, int> BigCnt;

int main()
{
	[&]() //Eratosthenes
	{
		notP[0] = notP[1] = true;
		for(int i=2; i<=MAX_NR; i++) if(notP[i] == false)
			for(int j=i+i; j<=MAX_NR; j+=i) notP[j] = true;
		for(int i=2; i<=MAX_NR; i++) if(notP[i] == false) Ps.push_back(i);
	}();
	long long ans = 1; bool isBig = false;
	auto pushAns = [&](int multi)
	{
		ans *= multi;
		if(ans >= MOD) isBig = true;
		ans %= MOD;
	};
	for(int k=1; k>=-1; k-=2)
	{
		int o; scanf("%d", &o);
		for(int l=0; l<o; l++)
		{
			int N; scanf("%d", &N);
			for(int i=0; i<Ps.size(); i++)
			{
				int p = Ps[i];
				while(N % p == 0) 
				{
					Cnt[i] += k, N /= p;
					if(k < 0 && Cnt[i] >= 0)
						pushAns(Ps[i]);
				}
			}
			if(N != 1) 
			{
				BigCnt[N] += k;
				if(k < 0 && BigCnt[N] >= 0)
					pushAns(N);
			}
		}
	}
	if(isBig) printf("%09d\n", (int)ans);
	else printf("%d\n", (int)ans);
	return 0;
}