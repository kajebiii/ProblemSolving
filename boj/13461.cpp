#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <queue>
#include <functional>

using namespace std;

typedef pair<double, int> pdi;
const double EPS = 1e-9;

struct PT {
	double cor[2];
	PT() {}
	PT(double x, double y) {cor[0] = x; cor[1] = y;}
	PT operator-(const PT &o) const { return PT(cor[0]-o.cor[0], cor[1]-o.cor[1]); }
	PT operator+(const PT &o) const { return PT(cor[0]+o.cor[0], cor[1]+o.cor[1]); }
	PT operator*(const double &o) const {return PT(cor[0]*o, cor[1]*o); }
	PT operator/(const double &o) const {return PT(cor[0]/o, cor[1]/o); }
	double operator/(const PT &o) const {
		for(int k=0; k<2; k++)
			if(abs(o.cor[k]) > EPS) return cor[k] / o.cor[k];
		printf("divide with zero vector");
		assert(false);
		return -1;
	}
	double len() const{return sqrt(cor[0] * cor[0] + cor[1] * cor[1]);}
	PT unit() const{return PT(cor[0], cor[1])/len(); }
	PT orth() const{return PT(cor[1], -cor[0]);}
	double dot(const PT &o) const{return cor[0]*o.cor[0] + cor[1]*o.cor[1];}
	PT trans(const PT &d_vec) const {
		PT d_uni = d_vec.unit(), y_uni = d_uni.orth();
		double x = dot(d_uni) / (d_uni.dot(d_uni));
		PT y_vec = (*this) - d_uni * x;
		double y = y_vec / y_uni;		
		return PT(x, y);
	}
	PT restore(const PT &d_vec) const {
		PT d_uni = d_vec.unit(), y_uni = d_uni.orth();
		return d_uni * cor[0] + y_uni * cor[1];
	}
	bool operator<(const PT &o) const {
		if(abs(cor[0] - o.cor[0]) > EPS) return cor[0] < o.cor[0];
		return cor[1] < o.cor[1];
	}
	void print() const{
		printf("%f %f\n", cor[0], cor[1]);
	}
};

const int MAX_N = 1e2 + 10, MAX_V = MAX_N * MAX_N;

vector<PT> Pts;
int N, S, E;
int ConInfo[MAX_N][2];
int Group[MAX_V];
vector<int> Convey[MAX_N];
vector<int> Ed[MAX_V];

void addEdge(int a, int b) { Ed[a].push_back(b);}
int newNode(int g) {
	double x, y;
	scanf("%lf%lf", &x, &y);
	Pts.push_back(PT(x, y));
	int cnt = Pts.size() - 1;
	Group[cnt] = g;
	return cnt;
}
int newNode(const PT &o, int g) {
	Pts.push_back(o);
	int cnt = Pts.size() - 1;
	Group[cnt] = g;
	return cnt;
}
void getInput() {
	S = newNode(-2); E = newNode(-1);
	scanf("%d", &N);
	for(int i=0; i<N; i++) for(int j=0; j<2; j++) Convey[i].push_back(newNode(i)), ConInfo[i][j] = Convey[i][j];
}
void initGraph() {
	for(int a=0; a<Pts.size(); a++) for(int b=a+1; b<Pts.size(); b++)
		if(Group[a] != Group[b])
			addEdge(a, b), addEdge(b, a);

	int beforeSize = Pts.size();
	for(int i=0; i<N; i++) {
		PT nowD = Pts[ConInfo[i][1]] - Pts[ConInfo[i][0]];
		PT left  = Pts[ConInfo[i][0]].trans(nowD);
		PT right = Pts[ConInfo[i][1]].trans(nowD);
		double y = left.cor[1];
		for(int p=0; p<beforeSize; p++) if(i != Group[p]) {
			PT base = Pts[p].trans(nowD);
			for(int k=-1; k<=1; k+=2) {
				PT val = base; 
				val.cor[0] += abs(y-base.cor[1]) / sqrt(3) * k;
				val.cor[1] = y;
				if(left < val && val < right || val < left && right < val)
				{
					int now = newNode(val.restore(nowD), i);
					Convey[i].push_back(now);
					addEdge(p, now);
					addEdge(now, p);
				}
			}
		}
	}

	for(int i=0; i<N; i++) {
		sort(Convey[i].begin(), Convey[i].end(), [&](auto a, auto b) {return Pts[a] < Pts[b];});
		if(Pts[ConInfo[i][0]] < Pts[ConInfo[i][1]])
			for(int k=1; k<Convey[i].size(); k++)
				addEdge(Convey[i][k-1], Convey[i][k]);
		else
			for(int k=1; k<Convey[i].size(); k++)
				addEdge(Convey[i][k], Convey[i][k-1]);
	}
}

double dijkstra() {
	vector<double> dis = vector<double>(Pts.size(), -100);
	vector<bool> vis = vector<bool>(Pts.size(), false);
	priority_queue<pdi, vector<pdi>, greater<pdi> > Q;
	Q.push(make_pair(0, S)); dis[S] = 0;
	while(!Q.empty()) {
		double d; int v; tie(d, v) = Q.top(); Q.pop();
		if(vis[v]) continue; vis[v] = true;
		if(v == E) break;
		for(int w : Ed[v]) {
			int ve = 1; if(Group[w] == Group[v]) ve = 2;
			double nd = d + (Pts[v] - Pts[w]).len() / ve;
			if(dis[w] < 0 || dis[w] > nd)
				Q.push(make_pair(dis[w] = nd, w));
		}
	}
	return dis[E];
}
int main() {
	getInput();
	initGraph();
	printf("%.10f\n", dijkstra());
	return 0;
}