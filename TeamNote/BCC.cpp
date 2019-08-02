//정점 BCC https://www.geeksforgeeks.org/biconnected-components/

int Pre, Ord[MAX_N]; stack<int> stk;
vector<vector<int>> Gs;
int bcc(int v, int p) {
	int low = Ord[v] = ++Pre;
	stk.push(v);
	bool first = true;
	for(int w : Ed[v]) {
		if(first && w == p) {
			first = false;
			continue;
		}
		if(Ord[w]) low = min(low, Ord[w]);
		else low = min(low, bcc(w, v));
	}
	if(low == Ord[v]) {
		Gs.push_back(vector<int>());
		while(!stk.empty() && Ord[v] <= Ord[stk.top()]) Gs.back().push_back(stk.top()), stk.pop();
	}
	return low;
}


//10806

//khsoo
void solve (int C, int P) {
	bool F = false;
	par[C] = P;
	ord[C] = ++cc;
	low[C] = ord[C];
	vis[C] = true;
	cur.push_back(C);
	for(auto &N : adj[C]) {
		if(!F && N == P) {
			F = true; continue;
		}
		if(vis[N]) low[C] = min(low[C], ord[N]);
		else {
			solve(N, C);
			low[C] = min(low[C], low[N]);
		}
	}
	if(low[C] == ord[C]) {
		while(!cur.empty() && ord[C] <= ord[cur.back()]) {
			int T = cur.back(); cur.pop_back();
			bcc[bc].push_back(T);
			wh[T] = bc;
		}
		cut[C] = true;
		bc++;
	}
}
