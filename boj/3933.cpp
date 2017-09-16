#include<iostream>

int dp[5][40010][210];
int S[5][40010][210];

int main()
{
	dp[0][0][0]=1;
	for(int m=0;m<200;m++) S[0][0][m]=1;

	for(int d=1;d<=4;d++) for(int n=1;n<40000;n++) for(int m=1;m<200;m++)
	{
		if(n-m*m>=0) dp[d][n][m]=S[d-1][n-m*m][m];
		S[d][n][m]=S[d][n][m-1]+dp[d][n][m];
	}

	for(;;)
	{
		int n;
		std::cin>>n;

		if(n==0) break;

		int A=0;
		for(int d=1;d<=4;d++) for(int p=1;p<200;p++) A=A+dp[d][n][p];

		std::cout<<A<<'\n';
	}

	return 0;
}

