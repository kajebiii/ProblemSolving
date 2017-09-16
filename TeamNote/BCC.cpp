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
