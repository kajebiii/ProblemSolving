#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> pi;

const int MAX_F = 1e5 + 100, MAX_N = 4e5 + 100;;

int F, N, Time[MAX_N];
map<string, pi> Ix; // string -> F, ix;
vector<int> Cost[MAX_F];
int Candy[MAX_F], Size[MAX_F];

multiset<pi> List[MAX_F]; //co / ix (if ix is big, restored)
multiset<int> Evolve[MAX_F]; //co

bool restore(int g, int co)
{
	if(Evolve[g].empty()) return false;
	int reCo = -(*Evolve[g].begin());
	if(reCo <= co) return false;
	List[g].insert(make_pair(reCo, MAX_F));
	Candy[g] += reCo;
	Evolve[g].erase(Evolve[g].begin());
	return true;
}
int calc(int g)
{
	int ch = 0;
	while(!List[g].empty())
	{
		int ix = List[g].begin() -> second, co = List[g].begin() -> first;
		if(co > Candy[g])
		{
//			printf("need more..! [[%d] %d | %d > %d]\n", List[g].empty(), List[g].begin() -> first, co, Candy[g]);
			if(restore(g, co)) ch--;
			else break;
		}
		ch++;
		Candy[g] -= co;
		Evolve[g].insert(-co);
		List[g].erase(List[g].begin());
		if(ix + 1 < Size[g])
			List[g].insert(make_pair(Cost[g][ix+1], ix+1));
	}
	return ch;
}

void init()
{
	scanf("%d", &F);
	for(int i=1; i<=F; i++)
	{
		Candy[i] = -1;
		int k; scanf("%d", &k);
		Size[i] = k;
		char name[30];
		Cost[i].push_back(0);
		for(int j=1; j<=k-1; j++)
		{
			scanf("%s", name);
			int co; scanf("%d", &co);
			Cost[i].push_back(co);
			Ix[name] = make_pair(i, j);
		}
		scanf("%s", name);
		Ix[name] = make_pair(i, k);
	}
}
int main()
{
	init();

	char name[30];
	scanf("%d", &N);
	int ev = 0, ans = 0, plus = 1;
	for(int i=1; i<=N; i++)
	{
		scanf("%d", &Time[i]);
		scanf("%s", name);
		pi now = Ix[name];
		int g = now.first, ix = now.second;
		Candy[g] += 4;
		if(ix < Size[g])
			List[g].insert(make_pair(Cost[g][ix], ix) );

		ev += calc(g);

		while(Time[plus] <= Time[i] - 1800) plus++;
		ans = max(ans, ev * 1000 + 100 * N + 100 * (i - plus + 1));
	}
	printf("%d\n", ans);
	return 0;
}