#include <bits/stdc++.h>
#include <math.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;

const int MAX_N = 50;
const int MAX_L = 55 * 55 * 4 * 4;
const bool debug = false;

using namespace std;

struct LINE {
	int point[2][2];
	double theta[2];
};

int N, M;
char Map[MAX_N+5][MAX_N+5];
int LightX, LightY;
LINE L[MAX_L];
int LN, Wall;
bool isBetween(int k, int x, int y) {
	if(x<=k && k<=y) return true;
	if(y<=k && k<=x) return true;
	return false;
}
bool isBetween(double k, double x, double y) {
	if(x<k && k<y) return true;
	if(y<k && k<x) return true;
	return false;
}
bool isBetweenEQ(double k, double x, double y) {
	if(x<=k && k<=y) return true;
	if(y<=k && k<=x) return true;
	return false;
}
double getLength(LINE l, double x, double y) {
	if(y == 0)
		return abs(l.point[0][0] - LightX);
	if(l.point[0][0] == l.point[1][0])
		return sqrt(x*x + y*y) / fabs(x) * abs(l.point[0][0] - LightX);
	return sqrt(x*x + y*y) / fabs(y) * abs(l.point[0][1] - LightY);
}
double getLength(LINE l, double theta) {
	if(theta == -M_PI_2)
		return getLength(l, 1, 0);
	else if(theta == M_PI_2)
		return getLength(l, -1, 0);
	else if(theta > -M_PI_2 || theta < M_PI_2)
		return getLength(l, tan(theta), 1);
	return getLength(l, tan(theta), -1);
}
void Input() {
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) {
		scanf("%s", Map[i]+1);
		for(int j=1; j<=M; j++) {
			if(Map[i][j] == '*') {
				LightX = i*2 - 1;
				LightY = j*2 - 1;
				Map[i][j] = '.';
			}
			if(Map[i][j] == '#')
				Wall++;
		}
	}
	for(int i=0; i<=N+1; i++)
		Map[i][0] = Map[i][M+1] = '#';
	for(int i=0; i<=M+1; i++)
		Map[0][i] = Map[N+1][i] = '#';
}
void MakeLines() {
	for(int i=0; i<=N; i++)
		for(int j=1; j<=M; j++)
			if(Map[i][j] == '#' || Map[i+1][j] == '#') {
				if(isBetween(LightY, (j-1) * 2, j * 2)) {
					++LN;
					L[LN] ={i * 2, (j-1) * 2, i * 2, LightY};
					++LN;
					L[LN] ={i * 2, LightY, i * 2, j * 2};
				} else {
					++LN;
					L[LN] ={i * 2, (j-1) * 2, i * 2, j * 2};
				}
			}
	for(int j=0; j<=M; j++)
		for(int i=1; i<=N; i++)
			if(Map[i][j] == '#' || Map[i][j+1] == '#') {
				if(isBetween(LightX, (i-1) * 2, i * 2)) {
					++LN;
					L[LN] ={(i-1) * 2, j * 2, LightX, j * 2};
					++LN;
					L[LN] ={LightX, j * 2, i * 2, j * 2};
				} else {
					++LN;
					L[LN] ={(i-1) * 2, j * 2, i * 2, j * 2};
				}
			}
	for(int l=1; l<=LN; l++) {
		for(int i=0; i<2; i++)
			L[l].theta[i] = atan2(L[l].point[i][0] - LightX, L[l].point[i][1] - LightY);
		sort(L[l].theta, L[l].theta + 2);
		if(L[l].theta[1] == M_PI && L[l].theta[0] < 0) {
			L[l].theta[1] = -M_PI;
			sort(L[l].theta, L[l].theta + 2);
		}
	}
}

vector<int> V[MAX_L];
int Cnt[MAX_L];
double Thetas[MAX_L * 2];
int ThetaN;
bool Check[MAX_L * 2];
queue<int> isZero;

void DrawGraph() {
	for(int i=1; i<=LN; i++)
		for(int j=1; j<=LN; j++) {
			if(i == j) continue;
			double theta = 0;
			bool flag = false;
			if(isBetween(L[i].theta[1], L[j].theta[0], L[j].theta[1])) {
				theta = L[i].theta[1];
				flag = true;
			}
			if(isBetween(L[i].theta[0], L[j].theta[0], L[j].theta[1])) {
				theta = L[i].theta[0];
				flag = true;
			}
			if(flag) {
				for(int k=0; k<2; k++) {
					if(theta == atan2(L[i].point[k][0] - LightX, L[i].point[k][1] - LightY)) {
						double li = getLength(L[i], L[i].point[k][0] - LightX, L[i].point[k][1] - LightY);
						double lj = getLength(L[j], L[i].point[k][0] - LightX, L[i].point[k][1] - LightY);
						if(li < lj)
							V[i].push_back(j), Cnt[j]++;
						else
							V[j].push_back(i), Cnt[i]++;

						continue;
					}
				}
			}
			if(L[i].theta[0] == L[j].theta[0] && L[i].theta[1] == L[j].theta[1]) {
				int l0 = -1, l1 = -1;
				for(int k0=0; k0<2; k0++)
					for(int k1=0; k1<2; k1++) {
						if(L[i].theta[0] == atan2(L[i].point[k0][0] - LightX, L[i].point[k0][1] - LightY))
							if(L[i].theta[0] == atan2(L[j].point[k1][0] - LightX, L[j].point[k1][1] - LightY)) {
								l0 = k0;
								l1 = k1;
								break;
							}
					}
				if(abs(L[i].point[l0][0] - LightX)  < abs(L[j].point[l1][0] - LightX) || abs(L[i].point[1-l0][0] - LightX)  < abs(L[j].point[1-l1][0] - LightX) || abs(L[i].point[l0][1] - LightY)  < abs(L[j].point[l1][1] - LightY) || abs(L[i].point[1-l0][1] - LightY)  < abs(L[j].point[1-l1][1] - LightY))
					V[i].push_back(j), Cnt[j]++;
				else
					V[j].push_back(i), Cnt[i]++;
			}
		}
	for(int i=1; i<=LN; i++) {
		Thetas[i*2-1] = L[i].theta[0];
		Thetas[i*2] = L[i].theta[1];
	}
	sort(Thetas + 1, Thetas + 2 * LN + 1);
	ThetaN = (int)(unique(Thetas, Thetas + 2 * LN + 1) - Thetas) - 1;
	for(int i=1; i<=LN; i++) if(Cnt[i] == 0) isZero.push(i);
	double result = 0;
	while(!isZero.empty()) {
		int now = isZero.front(); isZero.pop();
		for(int t=1; t<ThetaN; t++) {
			if(Check[t]) continue;
			if(isBetweenEQ(Thetas[t], L[now].theta[0], L[now].theta[1]) && isBetweenEQ(Thetas[t+1], L[now].theta[0], L[now].theta[1])) {
				Check[t] = true;
				result += 0.5 * fabs(getLength(L[now], Thetas[t]) * getLength(L[now], Thetas[t+1]) * sin(Thetas[t+1] - Thetas[t]));
			}
		}
		for(int next : V[now]) {
			Cnt[next]--;
			if(Cnt[next] == 0)
				isZero.push(next);
		}
	}
	printf("%.10lf\n", 1.0 * N * M - result / 4. - Wall);
}
int main() {
	Input();
	MakeLines();
	DrawGraph();
	return 0;
}