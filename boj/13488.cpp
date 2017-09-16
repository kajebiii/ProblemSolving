#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 5e5 + 100;

vector<int> List[MAX_N];
int Plus[MAX_N], N;
int Dw[MAX_N], Ef[MAX_N]; //Dwarf, Elf;

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) Plus[i] = -1;
	for(int i=0, x; i<N; i++) scanf("%d", &x), x--, Plus[x]++, List[x].push_back(i);
	for(int i=0; i<N; i++) scanf("%d", &Dw[i]);
	for(int i=0; i<N; i++) scanf("%d", &Ef[i]);
	
	int sum = 0, minV = MAX_N, minIx = -1;
	for(int i=0; i<N; i++)
		if((sum += Plus[i]) < minV)
			minV = sum, minIx = i;

	int s = (minIx + 1) % N;
	set<int> S; int ans = 0;
	for(int p=0; p<N; p++)
	{
		int i = (s+p) % N;
		for(int x : List[i]) S.insert(Ef[x]);
		auto ix = S.upper_bound(Dw[i]);
		if(ix == S.end())
			S.erase(S.begin());
		else
		{
			ans++;
			S.erase(ix);
		}
	}
	printf("%d\n", ans);
	return 0;
}