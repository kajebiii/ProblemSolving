#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 5e2 + 10;

int A, B, C, N, Dy[MAX_N];
int main() {
	cin >> A >> B >> C >> N;
	Dy[0] = 1;
	for(int i=0; i<=N; i++) Dy[i+A] |= Dy[i];
	for(int i=0; i<=N; i++) Dy[i+B] |= Dy[i];
	for(int i=0; i<=N; i++) Dy[i+C] |= Dy[i];
	printf("%d\n", Dy[N]);
	return 0;
}