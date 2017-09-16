#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAX_N = 5e1 + 22;
typedef pair<int, int> pi;

int N, Nr[MAX_N][MAX_N];
char Mp[MAX_N][MAX_N];
bool Chk[MAX_N][MAX_N];
vector<int> List;
pi S; int all = 0;

bool getPos(int d, int u) {
	int startV = Nr[S.first][S.second];
	if(startV < d || startV > u) return false;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) Chk[i][j] = false;
	int val = 0;
	queue<pi> Q; Q.push(S);
	Chk[S.first][S.second] = true;
	while(!Q.empty()) {
		pi now = Q.front(); Q.pop();
		if(Mp[now.first][now.second] == 'K') val++;
		for(int k=0; k<8; k++) {
			pi next = make_pair(now.first + "10120022"[k] - '1', now.second + "01210202"[k] - '1');
			if(next.first < 0 || next.second < 0) continue;
			if(next.first >= N || next.second >= N) continue;
			if(Chk[next.first][next.second] == true) continue;
			if(Nr[next.first][next.second] < d || Nr[next.first][next.second] > u) continue;
			Chk[next.first][next.second] = true;
			Q.push(next);
		}
	}
	if(val == all) return true;
	return false;
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s", Mp[i]);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &Nr[i][j]), List.push_back(Nr[i][j]);
	sort(List.begin(), List.end());
	List.erase(unique(List.begin(), List.end()), List.end());
	
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) 
		if(Mp[i][j] == 'K') all++;
		else if(Mp[i][j] == 'P') S = make_pair(i, j);

	int res = 0x7fffffff;

	int l = List.size();
	for(int i=0, j=0; i<l; ) {
		if(getPos(List[i], List[j])) {
			res = min(res, List[j] - List[i]);
			i++;
		}else{
			j++;
			if(j == l) break;
		}
	}
	printf("%d\n", res);
	return 0;
}