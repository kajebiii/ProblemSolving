#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int N, K;
struct T
{
	string uni, name;
	int ac, pa;
	T(string uni_, string name_, int ac_, int pa_) : uni(uni_), name(name_), ac(ac_), pa(pa_) {}
};
vector<T> Ts;
set<string> S;
int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++)
	{
		char un[55], na[55]; int a, p;
		scanf("%s%s%d%d", un, na, &a, &p);
		Ts.push_back(T(un, na, a, p));
	}
	sort(Ts.begin(), Ts.end(), [&](const T &a, const T &b)
	{
		if(a.ac != b.ac) return a.ac > b.ac;
		return a.pa < b.pa;
	});
	int ix = 0, k = 0;
	while(k < K)
	{
		if(S.count(Ts[ix].uni) == 0)
		{
			S.insert(Ts[ix].uni);
			printf("%s\n", Ts[ix].name.c_str());
			ix++;
			k++;
		}
		else ix++;
	}
	return 0;
}