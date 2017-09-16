#include <stdio.h>
#include <algorithm>

using namespace std;

struct NODE
{
	int l, r;
	NODE *lp, *rp;
	bool inv; int sum;

	NODE(int a, int b)
	{
		l = a; r = b; sum = 0;
		inv = false;

		if(a == b) return;

		int m = (a+b) >> 1;
		lp = new NODE(a, m);
		rp = new NODE(m+1, b);
	}
	void update(int a, int b, int x, int y)
	{
		if(b < x || y < a) return;
		if(x <= a && b <= y)
		{
			inv = !inv;
			sum = (b-a+1) - sum;
			return;
		}
		int m = (a+b) >> 1;
		lp->update(a, m  , x, y);
		rp->update(m+1, b, x, y);

		sum = lp->sum + rp->sum;
		if(inv) sum = b-a+1 - sum;
	}
	int get(int a, int b, int x, int y, bool now)
	{
		if(b < x || y < a) return 0;
		if(x <= a && b <= y) 
			return now?(b-a+1)-sum:sum;
		int m = (a+b) >> 1;
		now = (inv ? !now : now);
		int val = lp->get(a, m, x, y, now) + rp->get(m+1, b, x, y, now);
		return val;
	}
};

const int MAX_N = 1e5 + 100;

NODE *root;
int N, M;
int main()
{
	scanf("%d%d", &N, &M);
	root = new NODE(1, N);
	for(int _=0; _<M; _++)
	{
		int o, s, t; scanf("%d%d%d", &o, &s, &t);
		if(o == 0) root->update(1, N, s, t);
		else printf("%d\n", root->get(1, N, s, t, false));
	}
	return 0;
}