#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 1e3 + 10;

int N, Nr[MAX_N][2], Height[MAX_N][MAX_N];
vector<int> cor[2];

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) for(int j=0; j<2; j++)
			scanf("%d", &Nr[i][j]), cor[j].push_back(Nr[i][j]);
		for(int i=0; i<2; i++) cor[i].push_back(-1), cor[i].push_back(1e6);
		for(int j=0; j<2; j++) {
			sort(cor[j].begin(), cor[j].end());
			cor[j].erase(unique(cor[j].begin(), cor[j].end()), cor[j].end());
		}
		for(int i=0; i<N; i++) for(int j=0; j<2; j++)
			Nr[i][j] = lower_bound(cor[j].begin(), cor[j].end(), Nr[i][j]) - cor[j].begin();
		Nr[N][0] = Nr[0][0], Nr[N][1] = Nr[0][1];
		
		for(int i=0; i<cor[1].size(); i++) for(int j=0; j<cor[0].size(); j++) 
			Height[i][j] = 0;
		for(int i=0; i<N; i++) {
			if(Nr[i][1] != Nr[i+1][1]) continue;
			int a = Nr[i][0], b = Nr[i+1][0], k = 1;
			if(Nr[i][0] > Nr[i+1][0]) {
				swap(a, b);
				k = -1;
			}
			for(int j=a; j<b; j++)
				Height[Nr[i][1]-1][j] = k;
		}
		for(int j=0; j<cor[0].size(); j++) for(int i=cor[1].size()-2; i>=0; i--) {
			if(Height[i][j] != 0) continue;
			if(Height[i+1][j] > 0) Height[i][j] = Height[i+1][j] + 1;
			else if(Height[i+1][j] < 0) Height[i][j] = Height[i+1][j];
		}
		for(int i=cor[1].size()-1; i>=0; i--) for(int j=0; j<cor[0].size(); j++)
			if(Height[i][j] < 0) Height[i][j] = 0;

		int ans = 0;
		for(int i=cor[1].size()-1; i>=0; i--) {
			stack<int> S; S.push(0);
			for(int j=1; j<cor[0].size(); j++) {
				while(Height[i][S.top()] > Height[i][j]) {
					int r = j, h = Height[i][S.top()]; S.pop();
					int l = S.top() + 1;
					r = cor[0][r];
					l = cor[0][l];
					h = cor[1][i+h] - cor[1][i];
					ans = max(ans, min(r-l, h));
				}
				S.push(j);
			}
		}
		printf("%d\n", ans);
		for(int i=0; i<2; i++) {
			vector<int> temp;
			cor[i].swap(temp);
		}
	}
	return 0;
}
