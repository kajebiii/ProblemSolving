#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const int INF = 0x7fffffff;
typedef pair<int, int> pi;

vector<vector<int>> toV(int s) {
	vector<vector<int>> res = vector<vector<int>>(3, vector<int>(3, 0));
	for(int i=0; i<3; i++) for(int j=0; j<3; j++) 
		res[i][j] = (s>>(i*3+j))%2;
	return res;
}
int toS(vector<vector<int>> val) {
	int res = 0;
	for(int i=0; i<3; i++) for(int j=0; j<3; j++)
		res *= 2, res += val[i][j];
	return res;
}
vector<int> getList(int s) {
	vector<int> res;
	vector<vector<int>> ar = toV(s);
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) ar[i][j] = 1 - ar[i][j];
		res.push_back(toS(ar));
		for(int j=0; j<3; j++) ar[i][j] = 1 - ar[i][j];
	}
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) ar[j][i] = 1 - ar[j][i];
		res.push_back(toS(ar));
		for(int j=0; j<3; j++) ar[j][i] = 1 - ar[j][i];
	}
	for(int i=0; i<3; i++) ar[i][i] = 1 - ar[i][i];
	res.push_back(toS(ar));
	for(int i=0; i<3; i++) ar[i][i] = 1 - ar[i][i];
	for(int i=0; i<3; i++) ar[i][2-i] = 1 - ar[i][2-i];
	res.push_back(toS(ar));
	for(int i=0; i<3; i++) ar[i][2-i] = 1 - ar[i][2-i];

	return res;
}

vector<int> Dis;

int main() {
	Dis = vector<int>(1<<9, INF);
	Dis[0] = 0;
	queue<pi> Q; Q.push(make_pair(0, 0) );
	while(!Q.empty()) {
		int s, d; tie(s, d) = Q.front(); Q.pop();
		vector<int> list = getList(s);
		for(int w : list) if(Dis[w] == INF) {
			Dis[w] = d + 1;
			Q.push(make_pair(w, d+1));
		}
	}

	int T; scanf("%d", &T);
	vector<vector<int>> val = vector<vector<int>>(3, vector<int>(3, 0));
	while(T--)
	{
		for(int i=0; i<3; i++) for(int j=0; j<3; j++) {
			char x; scanf(" %c", &x);
			if(x == 'H') val[i][j] = 1;
			else val[i][j] = 0;
		}
		int now = Dis[toS(val)];
		for(int i=0; i<3; i++) for(int j=0; j<3; j++)
			val[i][j] = 1 - val[i][j];
		now = min(now, Dis[toS(val)]);
		if(now == INF) now = -1;
		printf("%d\n", now);
	}
	return 0;
}