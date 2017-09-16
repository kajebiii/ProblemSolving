
int ee(int a, int b, int &s, int &t) {
	if(!b) {
		s = 1, t = 0;
		return a;
	}
	int q = a/b, r = a%b, sp, tp;
	int g = ee(b, r, sp, tp);
	s = tp; t = sp-tp*q;
	return g;
}