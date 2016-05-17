#include<cstring>
#include<cstdio>
using namespace std;
#define N 10010
#define INF 0x1f1f1f1f
int map[N][N],dis[N],n;
bool flag[N];
int prim(int s,int n)
{
	int md,temp,total=0;
	memset(flag,false,sizeof(flag));
	memset(dis,0x1f,sizeof(dis));
	dis[s]=0;
	for (int i=1;i<=n;i++)
	 {
	 	md=INF;
	 	for (int j=1;j<=n;j++)
	 	 if (!flag[j]&&dis[j]<md)
	 	  temp=j,md=dis[j];
	 	total+=md;
		flag[temp]=true;
		for (int j=1;j<=n;j++)
		 if (!flag[j]&&map[temp][j]<dis[j])
		  dis[j]=map[temp][j];  
	 }
	return total; 
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	 scanf("%d",&map[i][j]);
	printf("%d\n",prim(1,n));
    }
}
