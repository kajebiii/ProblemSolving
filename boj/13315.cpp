#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cassert>
#include<stdlib.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

#define fi first
#define se second

const int LIM = 1000000000;

ll operator ^(const pii &l, const pii &r){
	return (ll)l.first * r.second - (ll)l.second * r.first;
}

pii operator -(const pii &l, const pii &r){
	return pii(l.first - r.first, l.second - r.second);
}

ll sq(ll x){ return x*x; }
ll sz(pii x){ return sq(x.first) + sq(x.second); }

void convex_hull(vector<pii> &D, vector<pii> &C){
	sort(D.begin(), D.end());
	D.erase(unique(D.begin(), D.end()), D.end());
	for(int i = 1; i < D.size(); i++) D[i] = D[i] - D[0]; D[0] = pii(0, 0);
	sort(D.begin()+1, D.end(), [](const pii &l, const pii &r){
		if( l^r ) return (l^r) < 0;
		return sz(l) < sz(r);
	});
	for(pii c : D){
		while(C.size() >= 2 && ((C[C.size()-2]-C.back() ^ (c - C.back())) <= 0 )) C.pop_back();
		C.push_back(c);
	}
}

void convex_hull_wrong(vector<pii> &D, vector<pii> &C){
	sort(D.begin(), D.end());
	D.erase(unique(D.begin(), D.end()), D.end());
	for(int i = 1; i < D.size(); i++) D[i] = D[i] - D[0]; D[0] = pii(0, 0);
	sort(D.begin()+1, D.end(), [](const pii &l, const pii &r){
		long double x = atan2(l.second, l.first), y = atan2(r.second, r.first);
		if( x == y ) return sz(l) < sz(r);
		return x > y;
	});
	for(pii c : D){
		while(C.size() >= 2 && ((C[C.size()-2]-C.back() ^ (c - C.back())) <= 0 )) C.pop_back();
		C.push_back(c);
	}
}
long double get(double a, double b)
{
	long double result = atan2(b, a);
	return result;
}

vector<pii> Ans;
int main()
{
	/*
	while(1)
	{
		int a = rand() % (LIM / 2) + 1, b =  rand() % (LIM / 2) + 1;
		int A = a, B = b;

		long double minK = get(A, B);
		bool find = false;
		while(A + a <= LIM && B + b <= LIM)
		{
			A += a; B += b;
			long double nowK = get(A, B);
			if(minK != nowK)
			{
				printf("%d %d -> [%d %d]\n", a, b, A, B);
				find = true;
				break;
			}
			minK = min(minK, nowK);
		}
		if(find == true) break;
	}
	*/

	int N = 5;
	int big = LIM;
	long double x, y, z;
	Ans.push_back(make_pair(-big, -big));
	Ans.push_back(make_pair(+big-2, big-3));
	Ans.push_back(make_pair(+big-1, big-2));
	Ans.push_back(make_pair(+big-0, big-1));
	Ans.push_back(make_pair(+big,   big));

	printf("%d\n", N);
	assert( 1 <= N && N <= 100);
	vector<pii> E, D, C;
	for(pii &X : Ans) {
		printf("%d %d\n", X.fi, X.se);
		assert( -LIM <= X.first && X.first <= LIM && -LIM <= X.second && X.second <= LIM);
		D.push_back(X);
	}
	return 0;
	convex_hull(D, C);
	convex_hull_wrong(D, E);

	//puts("ac"); for(pii &X : C) printf("%d %d\n", X.fi, X.se);
	//puts("wa"); for(pii &X : E) printf("%d %d\n", X.fi, X.se);

	sort(C.begin(), C.end());
	sort(E.begin(), E.end());

	assert(C != E);
	return 0;
}

