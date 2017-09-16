#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

struct TK
{
	int ix, x, y;
	TK(int ix_, int x_, int y_) : ix(ix_), x(x_), y(y_) {}
};
int N;
vector<TK> Ts;
vector<TK> Ans;
bool cmpX(TK A, TK B) { return A.x < B.x; }
bool cmpY(TK A, TK B) { return A.y < B.y; }

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Ts.push_back(TK(i, x, y));
	}
	sort(Ts.begin(), Ts.end(), cmpX);
	vector<TK> up, down;
	for(int i=1; i<=N; i++)
	{
		int diff = i - Ts[i-1].x;
		int t = abs(diff);
		int w = 0; if(t != 0) w = diff / t;
		for(int k=0; k<t; k++)
			if(w < 0)
				down.push_back(TK(Ts[i-1].ix, w, 0));
			else
				up.push_back(TK(Ts[i-1].ix, w, 0));
	}
	for(int k=0; k<down.size(); k++) Ans.push_back(down[k]);
	for(int k=0; k< up.size(); k++) Ans.push_back(up[up.size() - 1 - k]);
	up.clear(); down.clear();
	sort(Ts.begin(), Ts.end(), cmpY);
	for(int i=1; i<=N; i++)
	{
		int diff = i - Ts[i-1].y;
		int t = abs(diff);
		int w = 0; if(t != 0) w = diff / t;
		for(int k=0; k<t; k++)
			if(w < 0)
				down.push_back(TK(Ts[i-1].ix, 0, w));
			else
				up.push_back(TK(Ts[i-1].ix, 0, w));
	}
	for(int k=0; k<down.size(); k++) Ans.push_back(down[k]);
	for(int k=0; k< up.size(); k++) Ans.push_back(up[up.size() - 1 - k]);
	printf("%d\n", (int)Ans.size());
	map<pair<int, int>, char> M;
	M[make_pair(1, 0)] = 'D';
	M[make_pair(-1, 0)] = 'U';
	M[make_pair(0, 1)] = 'R';
	M[make_pair(0, -1)] = 'L';
	for(auto ans : Ans)
		printf("%d %c\n", ans.ix, M[make_pair(ans.x, ans.y)]);
	return 0;
}