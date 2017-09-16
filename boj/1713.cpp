#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> List;
int Cnt[111];
int main()
{
	int N, T; scanf("%d%d", &N, &T);
	for(int i=0; i<T; i++)
	{
		int x; scanf("%d", &x);
		if(find(List.begin(), List.end(), x) != List.end())
			Cnt[x]++;
		else if(List.size() < N)
		{
			List.push_back(x);
			Cnt[x]++;
		}
		else
		{
			int minV = -1, minCnt = 0x7fffffff;
			for(int &l : List) if(minCnt > Cnt[l]) {minCnt = Cnt[l], minV = l;}
			Cnt[minV] = 0;
			List.erase(find(List.begin(), List.end(), minV));

			List.push_back(x);
			Cnt[x]++;
		}
	}
	sort(List.begin(), List.end());
	for(int x : List) printf("%d ", x);
	return 0;
}