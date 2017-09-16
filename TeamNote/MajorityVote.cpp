
bool isDiff(int a, int b) {
	return a != b;
}
bool haveMajor(vector<int> candi) {
	if(SZ(candi) == 0) return false;
	vector<int> minor;
	vector<pi> rep;
	int nowX = -1, nowL = 0, maxL = 0;
	for(int x : candi) {
		if(nowX == -1) {
			nowX = x; nowL = maxL = 1;
		} else {
			if(!isDiff(nowX, x)) nowL++, maxL++;
			else {
				nowL--;
				minor.push_back(x);
				if(nowL == 0) {
					rep.push_back(pi(nowX, maxL));
					nowX = -1;
				}
			}
		}
	}
	if(nowX != -1) rep.push_back(pi(nowX, maxL));
	//    for(pi e : rep) printf("[%d %d] ", e.one, e.two); puts(""); for(int x : minor) printf("%d ", x); puts("");

	int mj = rep.back().one, cnt = 0;
	for(pi e : rep) if(!isDiff(mj, e.one)) cnt += e.two;
	for(int x : minor) if(!isDiff(mj, x)) cnt++;
    return cnt > SZ(candi) / 2;
}