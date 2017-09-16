#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> co[2];
int R[2][2][2];
bool Mp[7][7];

int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		for(int k=0; k<2; k++) for(int i=0; i<2; i++) for(int j=0; j<2; j++)
			scanf("%d", &R[k][i][j]), co[j].push_back(R[k][i][j]);
		for(int k=0; k<2; k++)
		{
			sort(co[k].begin(), co[k].end());
			co[k].erase(unique(co[k].begin(), co[k].end()), co[k].end());
		}
		for(int k=0; k<2; k++) for(int i=0; i<2; i++) for(int j=0; j<2; j++)
			R[k][i][j] = lower_bound(co[j].begin(), co[j].end(), R[k][i][j]) - co[j].begin();

		int ans = 0;
		for(int k=1; k>=0; k--)
		{
			for(int i=R[k][0][0]; i<R[k][1][0]; i++) for(int j=R[k][0][1]; j<R[k][1][1]; j++)
			{
				if(Mp[i][j] == false)
				{
					Mp[i][j] = true;
					if(k == 0) ans += (co[0][i+1] - co[0][i]) * (co[1][j+1] - co[1][j]);
				}
			}
		}
		printf("%d\n", ans);

		[&]()
		{
			for(int i=0; i<co[0].size(); i++) for(int j=0; j<co[1].size(); j++)
				Mp[i][j] = false;
			for(int k=0; k<2; k++)
				co[k].clear();
		}();
	}
	return 0;
}