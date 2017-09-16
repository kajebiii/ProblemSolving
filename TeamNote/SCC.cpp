#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REPO(i,n) for(int (i)=1; (i)<=(int)(n); (i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX = 10020;

int V, E;
vector < int > from[MAX];

void input() {
	scanf("%d%d", &V, &E);

	// �׷��� �ʱ�ȭ
	for(int i = 0; i < E; i++) {
		int f, s;
		scanf("%d%d", &f, &s);
		from[f].push_back(s);
	}
}

int stack[MAX], top, id[MAX], currentId, groupId[MAX];
vector < vector < int > > sccGroup;

int traverse(int node) {
	id[node] = ++currentId;
	stack[top++] = node;

	// lowlink�� return ������ ���
	int lowlink = id[node];
	for(auto next : from[node]) {
		if(id[next] == 0) {
			// �湮���� ���� ����
			lowlink = min(lowlink, traverse(next));
		} else if(groupId[next] == 0) {
			// �̹� ���ÿ� ��� �ִ� ����
			lowlink = min(lowlink, id[next]);
		}
	}

	if(lowlink == id[node]) {
		// �׷� �߰�
		sccGroup.push_back(vector<int>());
		while(1) {
			int now = stack[top-1];
			top--;

			// node ������ ����Ʈ���� SCC �׷����� ����
			groupId[now] = sccGroup.size();
			sccGroup[groupId[now]-1].push_back(now);

			if(now == node) break;
		}
	}

	return lowlink;
}

void solve() {
	for(int v = 1; v <= V; v++)
		if(id[v] == 0)
			traverse(v);

	// ���� �䱸 ���Ǵ�� ����
	for(auto &vec : sccGroup)
		sort(ALL(vec));
	sort(ALL(sccGroup));

	// ���
	printf("%d\n", sccGroup.size());
	for(auto &vec : sccGroup) {
		for(auto elem : vec) printf("%d ", elem);
		puts("-1");
	}
}

int main() {
	input();
	solve();
	return 0;
}