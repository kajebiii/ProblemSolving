#include <stdio.h>
#include <algorithm>

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
void draw(int k, int x, int y) {
	for(int i=x; i<x+7; i++) for(int j=y; j<y+5; j++)
		Ans[i][j] = Data[k][i-x][j-y];
}
int main() {
	char data[99];
	for(int i=0; i<99; i++) for(int j=0; j<22+4; j++) Ans[i][j] = ' ';
	Ans[2][14] = Ans[4][14] = 'o';
	while(scanf("%s", data) == 1) {
		if(data[0] == 'e') break;
		int h, m; sscanf(data, "%d:%d", &h, &m);
		draw(h/10, 0, 0);
		draw(h%10, 0, 7);
		draw(m/10, 0, 17);
		draw(m%10, 0, 24);
		for(int i=0; i<7; i++) printf("%s\n", Ans[i]); puts(""); puts("");
	}
	puts("end");
	return 0;
}