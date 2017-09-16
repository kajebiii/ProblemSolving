#include <stdio.h>
#include <map>

using namespace std;

const int MAX_N = 1e6 + 10;

int N, Nr[MAX_N], Cnt[MAX_N];
map<int, int> Ans;
int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	Nr[0] = Nr[1];
	int plusAns = 0;
	for(int i=1; i<=N; i++)
	{
		Cnt[i] = Cnt[i-1];
		if(Nr[i] > Nr[i-1]) Cnt[i]++;
		if(Nr[i] < Nr[i-1]) Cnt[i]--;

		int diff = Nr[i] - Nr[1];
		if(Cnt[i] == 0 && diff == 0) plusAns++;
		if(Cnt[i] != 0)
			if(abs(diff) % abs(Cnt[i]) == 0)
			{
				int value = diff/Cnt[i];
				if(Ans.count(value) == 0) Ans[value] = 0;
				Ans[value]++;
			}
	}
	if(Ans.size() == 0) Ans[0] = 0;
	int ansV = -1, ansN = -1;
	for(auto list : Ans)
		if(ansV < list.second + plusAns)
		{
			ansV = list.second + plusAns;
			ansN = list.first;
		}
	printf("%d\n%d\n", ansV, ansN);
	return 0;
}