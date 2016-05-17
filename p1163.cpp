#include<cstdio>
using namespace std;
int n,dp[101][101]={0};
int max(int x,int y){return x>y?x:y;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=i;j++)
		scanf("%d",&dp[i][j]);
	for (int i=n-1;i>=1;i--)
	 for (int j=1;j<=i;j++)
		dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
	printf("%d\n",dp[1][1]);
}
