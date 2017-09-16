#include <stdio.h>
#include <map>
#include <string>

using namespace std;

map<string, int> M;
int N;

int main()
{
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++)
	{
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
		{
			char name[55], cate[55];
			scanf("%s %s", name, cate);
			string cate_ = cate;
			if(M.count(cate) == 0) M[cate] = 0;
			M[cate]++;
		}
		long long ans = 1;
		for(auto &val : M)
			ans *= val.second + 1;
		ans--;
		printf("%lld\n", ans);
		M.clear();
	}
	return 0;
}