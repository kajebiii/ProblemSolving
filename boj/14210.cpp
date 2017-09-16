#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N;
vector<string> S;
map<int, bool> Mp;
int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		char getIn[111]; scanf("%s", getIn);
		S.push_back(getIn);
	}
	string now; char temp[111]; scanf("%s", temp); now = temp;

	for(int i=0; i<N; i++)
		if(S[i].substr(0, now.length()) == now)
			Mp[S[i][now.length()]] = true;

	for(int i=0; i<4; i++, puts("")) for(int j=0; j<8; j++)
		if(Mp[i*8+j+62] == true)
			printf("%c", i*8+j+62);
		else
			printf("*");
	return 0;
}