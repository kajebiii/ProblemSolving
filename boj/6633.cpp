#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

char Ans[99][99];
char Data[10][7][9] ={
	{
		"+---+",
		"|   |",
		"|   |",
		"+   +",
		"|   |",
		"|   |",
		"+---+"
	},
	{
		"    +",
		"    |",
		"    |",
		"    +",
		"    |",
		"    |",
		"    +"
	},
	{
		"+---+",
		"    |",
		"    |",
		"+---+",
		"|    ",
		"|    ",
		"+---+"
	},
	{
		"+---+",
		"    |",
		"    |",
		"+---+",
		"    |",
		"    |",
		"+---+"
	},
	{
		"+   +",
		"|   |",
		"|   |",
		"+---+",
		"    |",
		"    |",
		"    +"
	},
	{
		"+---+",
		"|    ",
		"|    ",
		"+---+",
		"    |",
		"    |",
		"+---+"
	},
	{
		"+---+",
		"|    ",
		"|    ",
		"+---+",
		"|   |",
		"|   |",
		"+---+"
	},
	{
		"+---+",
		"    |",
		"    |",
		"    +",
		"    |",
		"    |",
		"    +"
	},
	{
		"+---+",
		"|   |",
		"|   |",
		"+---+",
		"|   |",
		"|   |",
		"+---+"
	},
	{
		"+---+",
		"|   |",
		"|   |",
		"+---+",
		"    |",
		"    |",
		"+---+"
	},
};
vector<int> getList(int x, int y, int maxK) {
	bool isCan[10]; for(int i=0; i<=maxK; i++) isCan[i] = true;
	for(int i=0; i<7; i++) for(int j=0; j<5; j++) {
		char c = Ans[x+i][y+j];
		if(c == '+' || c == '|' || c == '-' || c == ' ') {
			for(int k=0; k<=maxK; k++) if(isCan[k])
				if(Data[k][i][j] != c) isCan[k] = false;
		}
	}
	vector<int> list;
	for(int i=0; i<=maxK; i++) if(isCan[i]) list.push_back(i);
	return list;
}
int main() {
	while(1) {
		fgets(Ans[0], 99, stdin);
		if(Ans[0][0] == 'e') break;
		for(int i=1; i<9; i++) fgets(Ans[i], 99, stdin);
		vector<int> h1 = getList(0, 0, 2);
		vector<int> h0 = getList(0, 7, 9);
		vector<int> m1 = getList(0, 17, 5);
		vector<int> m0 = getList(0, 24, 9);
		int cnt = 0;
		int ansh = -1, ansm = -1;
		for(int x : h1) for(int y : h0) {
			if(x * 10 + y <= 23) cnt++, ansh = x * 10 + y;
			if(cnt >= 2) break;
		}
		if(cnt >= 2) {puts("ambiguous"); continue;}
		cnt = 0;
		for(int x : m1) for(int y : m0) {
			if(x * 10 + y <= 59) cnt++, ansm = x * 10 + y;
			if(cnt >= 2) break;
		}
		if(cnt >= 2) puts("ambiguous");
		else printf("%02d:%02d\n", ansh, ansm);
	}
	puts("end");
	return 0;
}