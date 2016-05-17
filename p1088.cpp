#include<cstdio>
#include<cstring>
using namespace std;
int a[110][110],f[110][110];
const int dir[4][2]={1,0,0,1,-1,0,0,-1};
int ans,n,m;
int max(int a,int b){return a>b?a:b;}
int dp(int i,int j)
{
	if (f[i][j]>0) return f[i][j];
	int tempi,tempj;
	int maxn=0;
    for (int t=0;t<4;t++)
    {
    	tempi=i+dir[t][0];
    	tempj=j+dir[t][1];
    	if (tempi>0&&tempi<=n&&tempj>0&&tempj<=m)
    	{
    		if (a[tempi][tempj]<a[i][j])
    		 maxn=max(maxn,dp(tempi,tempj));
		}
	}
	return f[i][j]=maxn+1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  scanf("%d",&a[i][j]);
	memset(f,0,sizeof(f));
	ans=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	f[i][j]=dp(i,j);
	 	ans=max(ans,f[i][j]);
	 }
	printf("%d\n",ans);  
}
