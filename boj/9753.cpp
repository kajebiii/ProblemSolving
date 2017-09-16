#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5;

bool notP[MAX_N + 1];
vector<int> P;
vector<int> List;

int main()
{
	notP[1] = true; for(int i=2; i<=MAX_N; i++) if(notP[i] == false) for(int j=i*2; j<=MAX_N; j+=i) notP[j] = true;
	for(int i=1; i<=MAX_N; i++) if(notP[i] == false) P.push_back(i);
	for(int i=0; i<P.size(); i++)
	{
		for(int j=0; j<i; j++)
		{
			if(P[i] * P[j] >= 2*MAX_N) break;
			List.push_back(P[i] * P[j]);
		}
	}
	sort(List.begin(), List.end());
	List.erase(unique(List.begin(), List.end()), List.end());

	int T; scanf("%d", &T);
	while(T--)
	{
		int x; scanf("%d", &x);
		printf("%d\n", *lower_bound(List.begin(), List.end(), x));
	}
	return 0;
}