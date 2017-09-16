#include <stdio.h>
#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

string St, Sound;
string Last = "what does the fox say?";
set<string> S;

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; scanf("%d\n", &TC);
	
	while(TC--)
	{
		getline(cin, St);
		S.clear();
		while(1)
		{
			getline(cin, Sound);
			if(Sound == Last) break;
			int pos = Sound.find(' ', Sound.find(' ', 0) + 1);
			S.insert(Sound.substr(pos+1, Sound.size() - pos - 1));
		}
		St.append(" ");
		int left = 0, right = St.find(' ', left);
		while(right != -1)
		{
			string now = St.substr(left, right - left);
			if(S.count(now) == 0) cout << now << ' ';
			left = ++right;
			right = St.find(' ', right);
		}
		puts("");
	}

	return 0;
}