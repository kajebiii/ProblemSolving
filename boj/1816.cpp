#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e6;

bool notP[MAX_N+1];
vector<int> Ps;

int main()
{
	notP[1] = true;
	for(int i=2; i<=MAX_N; i++) if(notP[i] == false)
	{
		Ps.push_back(i);
		for(int j=i*2; j<=MAX_N; j+=i) notP[j] = true;
	}

	int T; scanf("%d", &T);
	while(T--)
	{
		long long val; scanf("%lld", &val);
		bool isTrue = true;
		for(int x : Ps) if(val % x == 0)
		{
			isTrue = false;
			break;
		}
		puts(isTrue?"YES":"NO");
	}
	return 0;
}