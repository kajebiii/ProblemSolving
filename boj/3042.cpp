#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct PT
{
	int x, y;
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT() : x(0), y(0) {}
};

const int MAX_N = 1e2 + 10;

int N; char C[MAX_N][MAX_N];
vector<PT> Ps;
int ccw(PT A, PT B, PT C)
{
	int val = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
	if(val > 0) return 1;
	if(val < 0) return -1;
	return 0;
}
int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%s", C[i] + 1);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(C[i][j] != '.') Ps.push_back(PT(i, j));
	int n = Ps.size();
	int ans = 0;
	for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) for(int k=j+1; k<n; k++)
		if(ccw(Ps[i], Ps[j], Ps[k]) == 0) ans++;
	printf("%d\n", ans);
	return 0;
}