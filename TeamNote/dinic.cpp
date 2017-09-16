

int S, E, l[700], si[700], Q[700];
struct ed
{
	int t, w, r;
	ed(int T, int W, int R) :t(T), w(W), r(R) {}
};
vector<ed> Mp[700];
void added(int f, int t, int w) {
	Mp[f].push_back(ed(t, w, Mp[t].size()));
	Mp[t].push_back(ed(f, 0, Mp[f].size()-1));
}
bool bfs()
{
	for(int i=0; i<=E; i++) l[i] = 0;
	int f=-1, r=-1;
	Q[++r]=S; l[S] = 1;
	while(f<r) {
		int x = Q[++f];
		for(auto &e: Mp[x])
			if(e.w != 0 && l[e.t] == 0) {
				Q[++r]=e.t; l[e.t] = l[x]+1;
				if(e.t == E) return true;
			}
	}
	return false;
}
int dfs(int x, int f) {
	if(x==E) return f;
	for(int &i=si[x], m; i<Mp[x].size(); i++) {
		auto &e=Mp[x][i];
		if(l[e.t]>l[x] && e.w!=0 && (m = dfs(e.t, min(f, e.w))) > 0) {
			e.w -= m;
			Mp[e.t][e.r].w += m;
			return m;
		}
	}
	return 0;
}
int main() {
	//input
	int flow = 0;
	while(true) {
		if(!bfs()) break;
		int f;
		for(int i=0; i<=E; i++) si[i] = 0;
		while((f=dfs(S, 10000000)) != 0) flow += f;
	}
	return 0;
}