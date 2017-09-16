#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<double> co[2];
double Nr[33][2][2];
int Ix[33][2][2];
bool isIn[66][66];

int main()
{
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		double x, y, w, h;
		scanf("%lf%lf%lf%lf", &x, &y, &w, &h);
		w += x; h += y;
		co[0].push_back(x), co[0].push_back(w);
		co[1].push_back(y), co[1].push_back(h);
		Nr[i][0][0] = x; Nr[i][0][1] = w;
		Nr[i][1][0] = y; Nr[i][1][1] = h;
	}
	for(int k=0; k<2; k++)
	{
		sort(co[k].begin(), co[k].end());
		co[k].erase(unique(co[k].begin(), co[k].end()), co[k].end());
	}
	for(int i=0; i<N; i++)
		for(int j=0; j<2; j++) for(int k=0; k<2; k++)
			Ix[i][j][k] = lower_bound(co[j].begin(), co[j].end(), Nr[i][j][k]) - co[j].begin();

	for(int i=0; i<N; i++)
		for(int x=Ix[i][0][0]; x<Ix[i][0][1]; x++) for(int y=Ix[i][1][0]; y<Ix[i][1][1]; y++)
			isIn[x][y] = true;
	double ans = 0;
	for(int i=0; i<co[0].size(); i++) for(int j=0; j<co[1].size(); j++)
		if(isIn[i][j])
			ans += (co[0][i+1] - co[0][i]) * (co[1][j+1] - co[1][j]);
	if((long long)(ans * 100) % 100 == 0) printf("%lld\n", (long long)ans);
	else printf("%.2lf\n", ans);
	return 0;
}