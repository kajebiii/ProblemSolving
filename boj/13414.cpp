#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<pair<int, string>> List;
map<string, int> Mp;

int main()
{
	int K, N; scanf("%d%d", &K, &N);
	for(int i=0; i<N; i++)
	{
		char getIx[99]; scanf("%s", getIx);
		Mp[getIx] = i;
	}
	for(auto &t : Mp) List.push_back(make_pair(t.second, t.first));
	sort(List.begin(), List.end());
	for(int i=0; i<min(K, (int)List.size()); i++)
	{
		string &ans = List[i].second;
		const char *p = ans.c_str();
		printf("%s\n", p);
	}
	return 0;
}