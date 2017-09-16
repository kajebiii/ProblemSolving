#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll MAXM = 5e6;
vector<ll> Nr, Pow;
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		Nr.clear();
		while(1)
		{
			ll x; scanf("%lld", &x);
			if(x == 0) break;
			Nr.push_back(x);
		}
		sort(Nr.begin(), Nr.end());
		reverse(Nr.begin(), Nr.end());
		Pow = Nr;
		
		int N = (int)Nr.size();
		ll sum = 0, plus = 0;
		bool isCan = true;
		for(int i=0; i<N; i++)
		{
			sum += 2 * Pow[i];
			plus = 0;
			for(int j=i+1; j<N; j++)
			{
				Pow[j] *= Nr[j];
				plus += 2 * Pow[j];
				if(plus > MAXM) isCan = false;
			}
			if(isCan == false || sum > MAXM) {isCan = false; break;}
		}
		if(!isCan) puts("Too expensive");
		else printf("%lld\n", sum);
	}
	return 0;
}