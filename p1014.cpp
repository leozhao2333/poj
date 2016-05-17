#include<cstdio>
#include<cstring>
using namespace std;
int a[10];
int dp[120005];
int cache=1;
int main()
{
    while (1)
    {
    	int sum=0;
    	for (int i=1;i<=6;i++)
    	 scanf("%d",&a[i]),sum+=i*a[i];
    	if (sum==0)return 0;    	
        printf("Collection #%d:\n",cache);
    	if(sum & 1) { printf("Can't be divided.\n\n");continue; }
    	sum=sum<<2;
    	memset(dp,0,sizeof(dp));
    	for (int i=1;i<=6;i++)
    	 for (int j=1;j<=sum;j++)
    	  dp[j]=max(dp[j],dp[j-i]+i);
	}
}
