#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 100, INF = 0x7fffffff;
struct PT
{
	int x, y;
};
PT P[MAX_N]; int N;
bool cmpX(PT &a, PT &b) { return a.x < b.x; }
bool cmpY(PT &a, PT &b) { return a.y < b.y; }

int getDis2(PT &a, PT &b)
{
	int dx = a.x - b.x, dy = a.y - b.y;
	return dx * dx + dy * dy;
}
int get(int a, int b)
{
	if(a == b) return INF;
	int m = (a+b) / 2;
	int mid_x = P[m].x;
	int l = get(a, m), r = get(m+1, b);
	int min_d_2 = min(l, r);
	vector<PT> candi;

	for(int i=a; i<=b; i++)
	{
		int diff_x = mid_x - P[i].x;
		if(diff_x * diff_x <= min_d_2)
			candi.push_back(P[i]);
	}
	sort(candi.begin(), candi.end(), cmpY);
	int d_lr = INF;
	for(int i=0; i<candi.size(); i++)
	{
		for(int j=i-6; j<=i+6; j++)
		{
			if(j < 0 || j >= candi.size()) continue;
			if(j == i) continue;
			d_lr = min(d_lr, getDis2(candi[i], candi[j]));
		}
	}
	return min(d_lr, min_d_2);
}
int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d%d", &P[i].x, &P[i].y);
	sort(P+1, P+N+1, cmpX);
	printf("%d", get(1, N));
	return 0;
}